module clock (output clk);
    reg clk;
    initial begin
        clk = 1'b0;
    end
    always begin
        #3 clk = ~clk;
    end
endmodule

module pulse ( signal, clock );
input clock;
output signal;
reg
signal;
always @ ( posedge clock )
begin
signal = 1'b1;
#36 signal = 1'b0;
#36 signal = 1'b1;
#36 signal = 1'b0;
#36 signal = 1'b1;
#36 signal = 1'b0;
end
endmodule // pulse

module principal;
    wire clk;
    wire p1, t1;
    reg p;
    clock clk_inst (clk);
    pulse pulse_inst (clk, p1);

    
    initial begin
        p = 1'b0;
    end
    
    initial begin
        $dumpfile("Guia_0904.vcd");
        $dumpvars;
        #120 $finish;
    end
endmodule
