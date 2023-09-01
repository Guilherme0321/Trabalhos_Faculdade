module Nand(output s, input a, b);
    wire notb;
    not NOT(notb,b);
    nand NAND(s,a,notb);
endmodule
module main;
    reg a, b;
    reg [2:0] counter = 0;
    wire s;
    Nand Port (.s(s), .a(a), .b(b));
    initial begin
        for (counter = 0; counter < 4; counter++) begin
            a = counter[1];
            b = counter[0];
            #10
            $display("%b   %d", counter[1:0],s);
        end
        $finish;
    end
endmodule
