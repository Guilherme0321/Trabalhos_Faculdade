import tkinter as tk
from tkinter import ttk, scrolledtext, messagebox
from models.instruction import InstructionStatus

from models.tomasuloSimulator import TomasuloSimulator

class TomasuloGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Simulador do Algoritmo de Tomasulo")
        
        # Obter dimensões da tela
        screen_width = root.winfo_screenwidth()
        screen_height = root.winfo_screenheight()
        
        # Calcular tamanho da janela (80% da tela, mas com limites mínimos e máximos)
        window_width = max(min(int(screen_width * 0.85), 1400), 1000)
        window_height = max(min(int(screen_height * 0.85), 900), 600)
        
        # Centralizar janela na tela
        pos_x = (screen_width - window_width) // 2
        pos_y = (screen_height - window_height) // 2
        
        self.root.geometry(f"{window_width}x{window_height}+{pos_x}+{pos_y}")
        self.root.configure(bg="#ffffff")
        self.root.minsize(1000, 600)  # Tamanho mínimo
        
        self.simulator = TomasuloSimulator()
        self.setup_ui()
        self.update_display()
    
    def setup_ui(self):
        # Estilo moderno e claro
        style = ttk.Style()
        style.theme_use("clam")
        
        # Configurar cores do tema claro
        style.configure("TFrame", background="#ffffff")
        style.configure("TLabelFrame", background="#ffffff", foreground="#2c3e50")
        style.configure("TLabelFrame.Label", background="#ffffff", foreground="#2c3e50", font=("Segoe UI", 10, "bold"))
        style.configure("TButton", background="#3498db", foreground="white", font=("Segoe UI", 9))
        style.map("TButton", 
                 background=[('active', '#2980b9'), ('pressed', '#21618c')])
        
        # Canvas principal com scrollbar
        self.main_canvas = tk.Canvas(self.root, bg="#ffffff", highlightthickness=0)
        main_scrollbar = ttk.Scrollbar(self.root, orient="vertical", command=self.main_canvas.yview)
        self.scrollable_frame = ttk.Frame(self.main_canvas)
        
        self.scrollable_frame.bind(
            "<Configure>",
            lambda e: self.main_canvas.configure(scrollregion=self.main_canvas.bbox("all"))
        )
        
        self.main_canvas.create_window((0, 0), window=self.scrollable_frame, anchor="nw")
        self.main_canvas.configure(yscrollcommand=main_scrollbar.set)
        
        # Empacotar canvas e scrollbar
        self.main_canvas.pack(side="left", fill="both", expand=True, padx=(15, 0), pady=15)
        main_scrollbar.pack(side="right", fill="y", padx=(0, 15), pady=15)
        
        # Bind do scroll do mouse
        def _on_mousewheel(event):
            self.main_canvas.yview_scroll(int(-1*(event.delta/120)), "units")
        
        self.main_canvas.bind_all("<MouseWheel>", _on_mousewheel)
        
        # Configurar redimensionamento do canvas
        def configure_canvas(event):
            canvas_width = event.width
            self.main_canvas.itemconfig(self.main_canvas.find_all()[0], width=canvas_width-20)
        
        self.main_canvas.bind('<Configure>', configure_canvas)
        
        # Frame principal dentro do scrollable_frame
        main_frame = ttk.Frame(self.scrollable_frame)
        main_frame.pack(fill=tk.BOTH, expand=True, padx=15, pady=15)
        
        # Título moderno
        title_label = tk.Label(main_frame, text="Simulador do Algoritmo de Tomasulo", 
                              font=("Segoe UI", 18, "bold"), bg="#ffffff", fg="#2c3e50")
        title_label.pack(pady=(0, 15))
        
        # Frame de controles com design moderno - altura fixa e compacta
        control_frame = ttk.LabelFrame(main_frame, text="Controles", padding=10)
        control_frame.pack(fill=tk.X, pady=(0, 10))
        
        # Botões de controle com estilo moderno
        btn_frame = ttk.Frame(control_frame)
        btn_frame.pack(fill=tk.X)
        
        # Estilo personalizado para botões
        style.configure("Modern.TButton", 
                       background="#3498db", 
                       foreground="white", 
                       font=("Segoe UI", 9, "bold"),
                       borderwidth=0,
                       focuscolor="none")
        style.map("Modern.TButton",
                 background=[('active', '#2980b9'), ('pressed', '#21618c')])
        
        ttk.Button(btn_frame, text="▶ Passo", command=self.step_simulation, style="Modern.TButton").pack(side=tk.LEFT, padx=(0, 8))
        ttk.Button(btn_frame, text="⏯ Executar", command=self.run_simulation, style="Modern.TButton").pack(side=tk.LEFT, padx=(0, 8))
        ttk.Button(btn_frame, text="🔄 Reset", command=self.reset_simulation, style="Modern.TButton").pack(side=tk.LEFT, padx=(0, 8))
        ttk.Button(btn_frame, text="📋 Carregar Exemplo", command=self.load_example, style="Modern.TButton").pack(side=tk.LEFT, padx=(0, 8))
        
        # Área de código com design moderno - altura fixa
        code_frame = ttk.LabelFrame(control_frame, text="Código MIPS", padding=8)
        code_frame.pack(fill=tk.X, pady=(10, 0))
        
        self.code_text = scrolledtext.ScrolledText(code_frame, height=4, font=("Consolas", 10),
                                                  bg="#f8f9fa", fg="#2c3e50", 
                                                  insertbackground="#3498db",
                                                  selectbackground="#e3f2fd")
        self.code_text.pack(fill=tk.X)
        
        ttk.Button(code_frame, text="🔧 Carregar Programa", command=self.load_program, style="Modern.TButton").pack(pady=(5, 0))
        
        # Frame de conteúdo principal - aqui vamos usar altura dinâmica
        content_frame = ttk.Frame(main_frame)
        content_frame.pack(fill=tk.BOTH, expand=True, pady=(10, 0))
        
        # Frame esquerdo - Métricas e Instruções
        left_frame = ttk.Frame(content_frame)
        left_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(0, 8))
        
        # Métricas com design moderno - altura fixa
        metrics_frame = ttk.LabelFrame(left_frame, text="📊 Métricas de Desempenho", padding=8)
        metrics_frame.pack(fill=tk.X, pady=(0, 8))
        
        self.metrics_text = tk.Text(metrics_frame, height=6, font=("Consolas", 9), 
                                   state=tk.DISABLED, bg="#f8f9fa", fg="#2c3e50",
                                   relief=tk.FLAT, borderwidth=1)
        self.metrics_text.pack(fill=tk.X)
        
        # Lista de instruções com design moderno - altura expansível
        instr_frame = ttk.LabelFrame(left_frame, text="📝 Status das Instruções", padding=8)
        instr_frame.pack(fill=tk.BOTH, expand=True)
        
        # Container com scrollbar para instruções
        instr_container = ttk.Frame(instr_frame)
        instr_container.pack(fill=tk.BOTH, expand=True)
        
        # Treeview para instruções com estilo moderno
        instr_columns = ("ID", "Instrução", "Status", "Issue", "Exec", "WB", "Commit", "ROB", "RS")
        self.instr_tree = ttk.Treeview(instr_container, columns=instr_columns, show="headings")
        
        # Configurar estilo do Treeview
        style.configure("Treeview", 
                       background="#ffffff",
                       foreground="#2c3e50",
                       fieldbackground="#ffffff",
                       font=("Segoe UI", 9))
        style.configure("Treeview.Heading", 
                       background="#ecf0f1",
                       foreground="#2c3e50",
                       font=("Segoe UI", 9, "bold"))
        
        for col in instr_columns:
            self.instr_tree.heading(col, text=col)
            self.instr_tree.column(col, width=70, minwidth=50)
        
        instr_scroll = ttk.Scrollbar(instr_container, orient=tk.VERTICAL, command=self.instr_tree.yview)
        self.instr_tree.configure(yscrollcommand=instr_scroll.set)
        
        self.instr_tree.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        instr_scroll.pack(side=tk.RIGHT, fill=tk.Y)
        
        # Frame direito - Estações de Reserva e ROB
        right_frame = ttk.Frame(content_frame)
        right_frame.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True, padx=(8, 0))
        
        # Estações de Reserva com design moderno - altura flexível
        rs_frame = ttk.LabelFrame(right_frame, text="🔧 Estações de Reserva", padding=8)
        rs_frame.pack(fill=tk.BOTH, expand=True, pady=(0, 4))
        
        rs_container = ttk.Frame(rs_frame)
        rs_container.pack(fill=tk.BOTH, expand=True)
        
        rs_columns = ("ID", "Busy", "Op", "Vj", "Vk", "Qj", "Qk", "Ciclos")
        self.rs_tree = ttk.Treeview(rs_container, columns=rs_columns, show="headings")
        
        for col in rs_columns:
            self.rs_tree.heading(col, text=col)
            self.rs_tree.column(col, width=60, minwidth=50)
        
        rs_scroll = ttk.Scrollbar(rs_container, orient=tk.VERTICAL, command=self.rs_tree.yview)
        self.rs_tree.configure(yscrollcommand=rs_scroll.set)
        
        self.rs_tree.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        rs_scroll.pack(side=tk.RIGHT, fill=tk.Y)
        
        # ROB com design moderno - altura flexível
        rob_frame = ttk.LabelFrame(right_frame, text="📋 Reorder Buffer (ROB)", padding=8)
        rob_frame.pack(fill=tk.BOTH, expand=True, pady=(4, 4))
        
        rob_container = ttk.Frame(rob_frame)
        rob_container.pack(fill=tk.BOTH, expand=True)
        
        rob_columns = ("Entry", "Instr", "Type", "Dest", "Value", "Ready")
        self.rob_tree = ttk.Treeview(rob_container, columns=rob_columns, show="headings")
        
        for col in rob_columns:
            self.rob_tree.heading(col, text=col)
            self.rob_tree.column(col, width=70, minwidth=50)
        
        rob_scroll = ttk.Scrollbar(rob_container, orient=tk.VERTICAL, command=self.rob_tree.yview)
        self.rob_tree.configure(yscrollcommand=rob_scroll.set)
        
        self.rob_tree.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        rob_scroll.pack(side=tk.RIGHT, fill=tk.Y)
        
        # Registradores com design moderno - altura fixa
        reg_frame = ttk.LabelFrame(right_frame, text="💾 Registradores", padding=8)
        reg_frame.pack(fill=tk.X, pady=(4, 0))
        
        self.reg_text = scrolledtext.ScrolledText(reg_frame, height=6, font=("Consolas", 8),
                                                 bg="#f8f9fa", fg="#2c3e50",
                                                 selectbackground="#e3f2fd")
        self.reg_text.pack(fill=tk.X)
    
    def load_example(self):
        example_code = """# ================================================================
# CÓDIGO MIPS OTIMIZADO PARA EXECUÇÃO PARALELA
# Demonstra diferentes tipos de paralelismo no algoritmo de Tomasulo
# ================================================================

# Bloco 1: Instruções completamente independentes (paralelismo total)
ADD R1, R2, R3      # R1 = R2 + R3 (pode executar imediatamente)
SUB R4, R5, R6      # R4 = R5 - R6 (pode executar em paralelo com ADD)
MUL R7, R8, R9      # R7 = R8 * R9 (pode executar em paralelo, unidade diferente)
LOAD R10, 100(R0)   # R10 = MEM[100] (pode executar em paralelo, unidade de load)

# Bloco 2: Cadeia de dependências com oportunidades de paralelismo
ADD R11, R1, R4     # R11 = R1 + R4 (depende de R1 e R4 do bloco anterior)
SUB R12, R7, R10    # R12 = R7 - R10 (depende de R7 e R10, mas independente de R11)
MUL R13, R2, R5     # R13 = R2 * R5 (independente, pode executar em paralelo)
DIV R14, R8, R3     # R14 = R8 / R3 (independente, pode executar em paralelo)

# Bloco 3: Mistura de operações aritméticas e de memória
LOAD R15, 200(R1)   # R15 = MEM[200 + R1] (depende de R1)
LOAD R16, 300(R4)   # R16 = MEM[300 + R4] (depende de R4, mas pode executar com R15)
ADD R17, R13, R14   # R17 = R13 + R14 (depende do bloco anterior)
SUB R18, R11, R12   # R18 = R11 - R12 (depende do bloco anterior)

# Bloco 4: Operações que exploram diferentes unidades funcionais
MUL R19, R15, R16   # R19 = R15 * R16 (multiplicação, depende dos loads)
ADD R20, R17, R18   # R20 = R17 + R18 (adição, pode executar em paralelo)
LOAD R21, 400(R2)   # R21 = MEM[400 + R2] (load independente)
DIV R22, R13, R8    # R22 = R13 / R8 (divisão, pode executar em paralelo)

# Bloco 5: Operações de store que testam o write-back
STORE R19, 500(R0)  # MEM[500] = R19 (depende de R19)
STORE R20, 600(R0)  # MEM[600] = R20 (pode executar em paralelo com store anterior)
ADD R23, R21, R22   # R23 = R21 + R22 (independente dos stores)
SUB R24, R19, R20   # R24 = R19 - R20 (depende de R19 e R20)

# Bloco 6: Sequência com branch (testa execução especulativa)
ADD R25, R23, R24   # R25 = R23 + R24
BEQ R25, R0, 2      # Se R25 == 0, pula 2 instruções (especulação)
MUL R26, R25, R21   # Instrução especulativa 1
SUB R27, R26, R22   # Instrução especulativa 2 (depende de R26)

# Bloco 7: Instruções após o branch (podem executar especulativamente)
ADD R28, R1, R2     # Operação independente
LOAD R29, 700(R3)   # Load independente
MUL R30, R28, R29   # R30 = R28 * R29 (depende das duas anteriores)
STORE R30, 800(R0)  # MEM[800] = R30 (finaliza com store)

# ================================================================
# ANÁLISE DE PARALELISMO ESPERADO:
# 
# Ciclo 1-4: Bloco 1 executa completamente em paralelo (4 instruções)
# Ciclo 5-8: Bloco 2 tem 2 instruções dependentes + 2 independentes
# Ciclo 9-12: Loads e operações aritméticas em paralelo
# Ciclo 13-16: Multiplicações e adições em unidades diferentes
# Ciclo 17-20: Stores e operações finais
# Ciclo 21+: Branch e execução especulativa
#
# IPC esperado: ~2.5-3.0 (depende das latências configuradas)
# ================================================================"""
        
        self.code_text.delete(1.0, tk.END)
        self.code_text.insert(1.0, example_code)
        self.load_program()
    
    def load_program(self):
        code = self.code_text.get(1.0, tk.END)
        try:
            self.simulator.load_program(code)
            self.simulator.reset()
            self.update_display()
            messagebox.showinfo("Sucesso", f"Programa carregado com {self.simulator.total_instructions} instruções")
        except Exception as e:
            messagebox.showerror("Erro", f"Erro ao carregar programa: {str(e)}")
    
    def step_simulation(self):
        if self.simulator.total_instructions == 0:
            messagebox.showwarning("Aviso", "Carregue um programa primeiro")
            return
        
        if not self.simulator.is_finished():
            self.simulator.step()
            self.update_display()
        else:
            messagebox.showinfo("Concluído", "Simulação finalizada!")
    
    def run_simulation(self):
        if self.simulator.total_instructions == 0:
            messagebox.showwarning("Aviso", "Carregue um programa primeiro")
            return
        
        max_cycles = 1000  # Limite de segurança
        cycles_run = 0
        
        while not self.simulator.is_finished() and cycles_run < max_cycles:
            self.simulator.step()
            cycles_run += 1
            
            # Atualizar display a cada 10 ciclos para não sobrecarregar
            if cycles_run % 10 == 0:
                self.update_display()
                self.root.update()
        
        self.update_display()
        
        if cycles_run >= max_cycles:
            messagebox.showwarning("Limite", "Simulação interrompida: limite de ciclos atingido")
        else:
            messagebox.showinfo("Concluído", f"Simulação finalizada em {self.simulator.cycle} ciclos!")
    
    def reset_simulation(self):
        self.simulator.reset()
        self.update_display()
    
    def update_display(self):
        self.update_metrics()
        self.update_instructions()
        self.update_reservation_stations()
        self.update_rob()
        self.update_registers()
    
    def update_metrics(self):
        metrics = self.simulator.get_metrics()
        
        self.metrics_text.config(state=tk.NORMAL)
        self.metrics_text.delete(1.0, tk.END)
        
        metrics_str = f"""MÉTRICAS DE DESEMPENHO
{'='*35}
IPC: {metrics['IPC']:.3f}  |  Ciclo: {metrics['Ciclos']}
Commitadas: {metrics['Instruções Commitadas']}/{metrics['Total de Instruções']}
Bolhas: {metrics['Ciclos de Bolha']}  |  Branches: {metrics['Branches Incorretos']}
Especulação: {metrics['Profundidade Especulativa']}

EFICIÊNCIA: {(metrics['IPC'] * 100):.1f}%  |  PROGRESSO: {(metrics['Instruções Commitadas'] / max(metrics['Total de Instruções'], 1) * 100):.1f}%"""
        
        self.metrics_text.insert(1.0, metrics_str)
        self.metrics_text.config(state=tk.DISABLED)
    
    def update_instructions(self):
        # Limpar árvore
        for item in self.instr_tree.get_children():
            self.instr_tree.delete(item)
        
        # Adicionar instruções
        for instr in self.simulator.instructions:
            issue = instr.issue_cycle if instr.issue_cycle >= 0 else "-"
            exec_start = instr.exec_start_cycle if instr.exec_start_cycle >= 0 else "-"
            wb = instr.write_back_cycle if instr.write_back_cycle >= 0 else "-"
            commit = instr.commit_cycle if instr.commit_cycle >= 0 else "-"
            rob = instr.rob_entry if instr.rob_entry >= 0 else "-"
            rs = instr.reservation_station if instr.reservation_station >= 0 else "-"
            
            # Colorir baseado no status com cores modernas e claras
            tag = ""
            if instr.status == InstructionStatus.COMMITTED:
                tag = "committed"
            elif instr.status == InstructionStatus.EXECUTING:
                tag = "executing"
            elif instr.status == InstructionStatus.ISSUED:
                tag = "issued"
            
            self.instr_tree.insert("", tk.END, values=(
                instr.id,
                instr.original_line[:15] + "..." if len(instr.original_line) > 15 else instr.original_line,
                instr.status.value,
                issue,
                exec_start,
                wb,
                commit,
                rob,
                rs
            ), tags=(tag,))
        
        # Configurar cores modernas e claras
        self.instr_tree.tag_configure("committed", background="#e8f5e8", foreground="#27ae60")
        self.instr_tree.tag_configure("executing", background="#fff8e1", foreground="#f39c12")
        self.instr_tree.tag_configure("issued", background="#e3f2fd", foreground="#3498db")
    
    def update_reservation_stations(self):
        # Limpar árvore
        for item in self.rs_tree.get_children():
            self.rs_tree.delete(item)
        
        # Adicionar estações
        for i, station in enumerate(self.simulator.reservation_stations):
            station_type = ""
            if i < self.simulator.num_add_stations:
                station_type = "ADD"
            elif i < self.simulator.num_add_stations + self.simulator.num_mul_stations:
                station_type = "MUL"
            else:
                station_type = "LOAD"
            
            busy = "Sim" if station.busy else "Não"
            op = station.op.value if station.op else "-"
            vj = f"{station.vj:.1f}" if station.vj is not None else "-"
            vk = f"{station.vk:.1f}" if station.vk is not None else "-"
            qj = station.qj if station.qj else "-"
            qk = station.qk if station.qk else "-"
            cycles = station.cycles_remaining if station.busy else "-"
            
            tag = "busy" if station.busy else "free"
            
            self.rs_tree.insert("", tk.END, values=(
                f"{station_type}{i}",
                busy,
                op,
                vj,
                vk,
                qj,
                qk,
                cycles
            ), tags=(tag,))
        
        # Configurar cores modernas e claras
        self.rs_tree.tag_configure("busy", background="#ffebee", foreground="#e74c3c")
        self.rs_tree.tag_configure("free", background="#e8f5e8", foreground="#27ae60")
    
    def update_rob(self):
        # Limpar árvore
        for item in self.rob_tree.get_children():
            self.rob_tree.delete(item)
        
        # Adicionar entradas do ROB
        for i, entry in enumerate(self.simulator.rob):
            instr_id = entry.instruction_id if entry.instruction_id >= 0 else "-"
            entry_type = entry.type.value if entry.type else "-"
            dest = entry.destination if entry.destination else "-"
            value = f"{entry.value:.1f}" if entry.value is not None else "-"
            ready = "Sim" if entry.ready else "Não"
            
            tag = ""
            if entry.instruction_id >= 0:
                if entry.ready:
                    tag = "ready"
                else:
                    tag = "busy"
            
            self.rob_tree.insert("", tk.END, values=(
                f"ROB{i}",
                instr_id,
                entry_type,
                dest,
                value,
                ready
            ), tags=(tag,))
        
        # Configurar cores modernas e claras
        self.rob_tree.tag_configure("ready", background="#e8f5e8", foreground="#27ae60")
        self.rob_tree.tag_configure("busy", background="#fff8e1", foreground="#f39c12")
    
    def update_registers(self):
        self.reg_text.delete(1.0, tk.END)
        
        reg_str = "BANCO DE REGISTRADORES\n"
        reg_str += "=" * 40 + "\n\n"
        
        # Mostrar registradores em colunas compactas
        for i in range(0, 32, 4):
            line = ""
            for j in range(4):
                if i + j < 32:
                    reg_name = f"R{i+j}"
                    value = self.simulator.register_file.registers[reg_name]
                    qi = self.simulator.register_file.qi[reg_name]
                    
                    if qi:
                        line += f"{reg_name:>2}:{value:>5.1f}({qi:<3}) "
                    else:
                        line += f"{reg_name:>2}:{value:>5.1f}     "
            
            reg_str += line + "\n"
        
        reg_str += "\nLegenda: Reg:Valor(ROB)"
        
        self.reg_text.insert(1.0, reg_str)