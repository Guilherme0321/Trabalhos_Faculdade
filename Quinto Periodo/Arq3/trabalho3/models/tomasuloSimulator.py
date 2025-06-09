from typing import List, Dict, Optional, Tuple
import re
from models.branchPredictor import BranchPredictor

from models.instruction import Instruction, InstructionStatus, InstructionType
from models.registerFile import RegisterFile
from models.reservationStation import ReservationStation
from models.robEntry import ROBEntry

class TomasuloSimulator:
    def __init__(self):
        self.instructions: List[Instruction] = []
        self.reservation_stations: List[ReservationStation] = []
        self.rob: List[ROBEntry] = []
        self.register_file = RegisterFile()
        self.branch_predictor = BranchPredictor()
        
        
        self.num_add_stations = 3
        self.num_mul_stations = 2
        self.num_load_stations = 2
        self.rob_size = 16
        
        
        self.latencies = {
            InstructionType.ADD: 1,
            InstructionType.SUB: 1,
            InstructionType.MUL: 3,
            InstructionType.DIV: 6,
            InstructionType.LOAD: 2,
            InstructionType.STORE: 1,
            InstructionType.BEQ: 1,
            InstructionType.BNE: 1
        }
        
        
        self.cycle = 0
        self.pc = 0
        self.total_instructions = 0
        self.committed_instructions = 0
        self.bubble_cycles = 0
        self.mispredicted_branches = 0
        self.speculation_depth = 0
        
        self.reset()
    
    def reset(self):
        self.cycle = 0
        self.pc = 0
        self.committed_instructions = 0
        self.bubble_cycles = 0
        self.mispredicted_branches = 0
        self.speculation_depth = 0
        
        for instr in self.instructions:
            instr.status = InstructionStatus.WAITING
            instr.issue_cycle = -1
            instr.exec_start_cycle = -1
            instr.exec_end_cycle = -1
            instr.write_back_cycle = -1
            instr.commit_cycle = -1
            instr.rob_entry = -1
            instr.reservation_station = -1
        
        
        self.reservation_stations = []
        station_id = 0
        
        
        for i in range(self.num_add_stations):
            self.reservation_stations.append(ReservationStation(station_id))
            station_id += 1
        
        
        for i in range(self.num_mul_stations):
            self.reservation_stations.append(ReservationStation(station_id))
            station_id += 1
        
        
        for i in range(self.num_load_stations):
            self.reservation_stations.append(ReservationStation(station_id))
            station_id += 1
        
        
        self.rob = [ROBEntry(i) for i in range(self.rob_size)]
        
        
        self.register_file = RegisterFile()
        
        
        self.register_file.registers["R1"] = 10.0
        self.register_file.registers["R2"] = 20.0
        self.register_file.registers["R3"] = 5.0
        self.register_file.registers["R4"] = 15.0
    
    def parse_instruction(self, line: str, instruction_id: int) -> Optional[Instruction]:
        line = line.strip().upper()
        if not line or line.startswith('#'):
            return None
        
        
        if '#' in line:
            line = line[:line.index('#')].strip()
        
        parts = re.split(r'[,\s]+', line)
        if len(parts) < 2:
            return None
        
        instr = Instruction(id=instruction_id, type=InstructionType.ADD, original_line=line)
        
        try:
            if parts[0] in ['ADD', 'SUB']:
                instr.type = InstructionType(parts[0])
                instr.rd = parts[1]
                instr.rs = parts[2]
                instr.rt = parts[3]
            
            elif parts[0] in ['MUL', 'DIV']:
                instr.type = InstructionType(parts[0])
                instr.rd = parts[1]
                instr.rs = parts[2]
                instr.rt = parts[3]
            
            elif parts[0] == 'LOAD':
                instr.type = InstructionType.LOAD
                instr.rd = parts[1]
                
                if '(' in parts[2]:
                    addr_parts = parts[2].split('(')
                    instr.immediate = int(addr_parts[0]) if addr_parts[0] else 0
                    instr.rs = addr_parts[1].rstrip(')')
                else:
                    instr.rs = parts[2]
            
            elif parts[0] == 'STORE':
                instr.type = InstructionType.STORE
                instr.rs = parts[1]  
                if '(' in parts[2]:
                    addr_parts = parts[2].split('(')
                    instr.immediate = int(addr_parts[0]) if addr_parts[0] else 0
                    instr.rt = addr_parts[1].rstrip(')')
                else:
                    instr.rt = parts[2]
            
            elif parts[0] in ['BEQ', 'BNE']:
                instr.type = InstructionType(parts[0])
                instr.rs = parts[1]
                instr.rt = parts[2]
                instr.immediate = int(parts[3])  
            
            else:
                return None
            
            return instr
            
        except (IndexError, ValueError):
            return None
    
    def load_program(self, code: str):
        self.instructions = []
        lines = code.strip().split('\n')
        instruction_id = 0
        
        for line in lines:
            instr = self.parse_instruction(line, instruction_id)
            if instr:
                self.instructions.append(instr)
                instruction_id += 1
        
        self.total_instructions = len(self.instructions)
    
    def can_issue(self, instr: Instruction) -> Tuple[bool, Optional[int], Optional[int]]:
        
        station_type = self.get_station_type(instr.type)
        available_station = None
        
        for i, station in enumerate(self.reservation_stations):
            if not station.busy and self.is_compatible_station(station, station_type, i):
                available_station = i
                break
        
        if available_station is None:
            return False, None, None
        
        
        available_rob = None
        for i, rob_entry in enumerate(self.rob):
            if rob_entry.instruction_id == -1:
                available_rob = i
                break
        
        if available_rob is None:
            return False, None, None
        
        return True, available_station, available_rob
    
    def get_station_type(self, instr_type: InstructionType) -> str:
        if instr_type in [InstructionType.ADD, InstructionType.SUB]:
            return "ADD"
        elif instr_type in [InstructionType.MUL, InstructionType.DIV]:
            return "MUL"
        else:
            return "LOAD"
    
    def is_compatible_station(self, station: ReservationStation, station_type: str, station_idx: int) -> bool:
        if station_type == "ADD":
            return station_idx < self.num_add_stations
        elif station_type == "MUL":
            return self.num_add_stations <= station_idx < self.num_add_stations + self.num_mul_stations
        else:  
            return station_idx >= self.num_add_stations + self.num_mul_stations
    
    def issue_instruction(self, instr: Instruction, station_idx: int, rob_idx: int):
        station = self.reservation_stations[station_idx]
        rob_entry = self.rob[rob_idx]
        
        
        station.busy = True
        station.op = instr.type
        station.instruction_id = instr.id
        station.cycles_remaining = self.latencies[instr.type]
        
        
        rob_entry.instruction_id = instr.id
        rob_entry.type = instr.type
        rob_entry.destination = instr.rd if instr.rd else ""
        
        
        if instr.rs:
            val, qi = self.register_file.read(instr.rs)
            if qi is None:
                station.vj = val
                station.qj = None
            else:
                station.vj = None
                station.qj = qi
        
        if instr.rt:
            val, qi = self.register_file.read(instr.rt)
            if qi is None:
                station.vk = val
                station.qk = None
            else:
                station.vk = None
                station.qk = qi
        
        
        if instr.type in [InstructionType.BEQ, InstructionType.BNE]:
            rob_entry.speculative = True
            self.speculation_depth += 1
        
        
        if instr.rd and instr.type not in [InstructionType.STORE, InstructionType.BEQ, InstructionType.BNE]:
            self.register_file.set_pending(instr.rd, f"ROB{rob_idx}")
        
        
        instr.status = InstructionStatus.ISSUED
        instr.issue_cycle = self.cycle
        instr.reservation_station = station_idx
        instr.rob_entry = rob_idx
    
    def execute_instructions(self):
        for station in self.reservation_stations:
            if station.busy and station.cycles_remaining > 0:
                
                if (station.qj is None or self.is_value_ready(station.qj)) and \
                   (station.qk is None or self.is_value_ready(station.qk)):
                    
                    
                    if station.qj:
                        station.vj = self.get_rob_value(station.qj)
                        station.qj = None
                    if station.qk:
                        station.vk = self.get_rob_value(station.qk)
                        station.qk = None
                    
                    
                    station.cycles_remaining -= 1
                    
                    
                    instr = next(i for i in self.instructions if i.id == station.instruction_id)
                    if instr.exec_start_cycle == -1:
                        instr.exec_start_cycle = self.cycle
                        instr.status = InstructionStatus.EXECUTING
    
    def write_back(self):
        completed_stations = []
        
        for i, station in enumerate(self.reservation_stations):
            if station.busy and station.cycles_remaining == 0:
                instr = next(inst for inst in self.instructions if inst.id == station.instruction_id)
                rob_entry = self.rob[instr.rob_entry]
                
                
                result = self.calculate_result(station, instr)
                
                
                rob_entry.value = result
                rob_entry.ready = True
                
                
                instr.status = InstructionStatus.WRITE_BACK
                instr.exec_end_cycle = self.cycle
                instr.write_back_cycle = self.cycle
                
                
                self.broadcast_result(f"ROB{instr.rob_entry}", result)
                
                completed_stations.append(i)
        
        
        for i in completed_stations:
            self.reservation_stations[i].busy = False
            self.reservation_stations[i].op = None
            self.reservation_stations[i].instruction_id = -1
    
    def calculate_result(self, station: ReservationStation, instr: Instruction) -> float:
        if station.op == InstructionType.ADD:
            return (station.vj or 0) + (station.vk or 0)
        elif station.op == InstructionType.SUB:
            return (station.vj or 0) - (station.vk or 0)
        elif station.op == InstructionType.MUL:
            return (station.vj or 0) * (station.vk or 0)
        elif station.op == InstructionType.DIV:
            return (station.vj or 0) / max(station.vk or 1, 0.001)  
        elif station.op == InstructionType.LOAD:
            
            addr = (station.vj or 0) + instr.immediate
            return addr % 100  
        else:
            return station.vj or 0
    
    def broadcast_result(self, tag: str, value: float):
        for station in self.reservation_stations:
            if station.qj == tag:
                station.vj = value
                station.qj = None
            if station.qk == tag:
                station.vk = value
                station.qk = None
    
    def is_value_ready(self, tag: str) -> bool:
        if not tag or not tag.startswith("ROB"):
            return True
        
        rob_idx = int(tag[3:])
        return self.rob[rob_idx].ready
    
    def get_rob_value(self, tag: str) -> float:
        if not tag or not tag.startswith("ROB"):
            return 0.0
        
        rob_idx = int(tag[3:])
        return self.rob[rob_idx].value or 0.0
    
    def commit_instructions(self):
        
        committed_this_cycle = 0
        
        for i in range(self.rob_size):
            rob_entry = self.rob[i]
            
            if rob_entry.instruction_id == -1:
                continue
            
            if not rob_entry.ready:
                break  
            
            instr = next(inst for inst in self.instructions if inst.id == rob_entry.instruction_id)
            
            
            if rob_entry.destination and rob_entry.type not in [InstructionType.STORE, InstructionType.BEQ, InstructionType.BNE]:
                self.register_file.write(rob_entry.destination, rob_entry.value, f"ROB{i}")
            
            
            if rob_entry.type in [InstructionType.BEQ, InstructionType.BNE]:
                self.handle_branch_commit(instr, rob_entry)
            
            
            instr.status = InstructionStatus.COMMITTED
            instr.commit_cycle = self.cycle
            self.committed_instructions += 1
            
            
            rob_entry.instruction_id = -1
            rob_entry.type = None
            rob_entry.destination = ""
            rob_entry.value = None
            rob_entry.ready = False
            rob_entry.speculative = False
            
            committed_this_cycle += 1
            
            
            if committed_this_cycle >= 2:
                break
    
    def handle_branch_commit(self, instr: Instruction, rob_entry: ROBEntry):
        
        self.speculation_depth = max(0, self.speculation_depth - 1)
        
        
        import random
        actual_taken = random.random() < 0.3
        predicted_taken = self.branch_predictor.predict(instr.id)
        
        if actual_taken != predicted_taken:
            self.mispredicted_branches += 1
            self.bubble_cycles += 3  
        
        self.branch_predictor.update(instr.id, actual_taken)
    
    def step(self):
        self.cycle += 1
        
        
        self.commit_instructions()
        
        
        self.write_back()
        
        
        self.execute_instructions()
        
        
        if self.pc < len(self.instructions):
            instr = self.instructions[self.pc]
            if instr.status == InstructionStatus.WAITING:
                can_issue, station_idx, rob_idx = self.can_issue(instr)
                if can_issue:
                    self.issue_instruction(instr, station_idx, rob_idx)
                    self.pc += 1
                else:
                    self.bubble_cycles += 1
    
    def is_finished(self) -> bool:
        return self.committed_instructions >= self.total_instructions and self.total_instructions > 0
    
    def get_ipc(self) -> float:
        return self.committed_instructions / max(self.cycle, 1)
    
    def get_metrics(self) -> Dict[str, float]:
        return {
            "IPC": self.get_ipc(),
            "Ciclos": self.cycle,
            "Instruções Commitadas": self.committed_instructions,
            "Total de Instruções": self.total_instructions,
            "Ciclos de Bolha": self.bubble_cycles,
            "Branches Incorretos": self.mispredicted_branches,
            "Profundidade Especulativa": self.speculation_depth
        }
