module clock (output clk);
    reg clk;
    initial begin
        clk = 1'b0;
    end
    always begin
        #12 clk = ~clk;
    end
endmodule

module pulse (input wire clock, output wire signal_out);
    reg signal_pulse;
    always @(posedge clock) begin
        #3 signal_pulse = 1'b0;
        #3 signal_pulse = 1'b1;
    end
    assign signal_out = signal_pulse;
endmodule

module trigger (input wire on, input wire clock, output wire signal_out);
    reg signal_trigger;
    always @(posedge clock) begin
        if (on) begin
            #60 signal_trigger = 1'b1;
            #60 signal_trigger = 1'b0;
        end
    end
    assign signal_out = signal_trigger;
endmodule

module principal;
    wire clk;
    wire p1, t1;
    reg p;
    clock clk_inst (clk);
    pulse pulse_inst (clk, p1);
    trigger trigger_inst (p, clk, t1);
    
    initial begin
        p = 1'b0;
    end
    
    initial begin
        $dumpfile("Guia_0901.vcd");
        $dumpvars(1, principal);
        
        // Simule os sinais
        
        #120 $finish;
    end
endmodule
