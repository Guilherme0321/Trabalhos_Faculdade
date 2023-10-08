module Resumido(output s, input a, b, c);
    assign s = (~a & ~b & ~c) | (~a & ~b & c) | (~a & b & ~c) | (~a & b & c) | (a & ~b & ~c) | (a & ~b & c) | (a & b & ~c) | (a & b & c); 
endmodule

module main;
    reg a, b, c;
    wire s;
 
    reg [4:0] counter = 0;

    Resumido exe1(.s(s),.a(a),.b(b),.c(c));
    initial begin
        for (counter = 0; counter < 16; counter++) begin
            a = counter[2];
            b = counter[1];
            c = counter[0];
            #0;
            $display("%d", s);
        end
        $finish;

    end
endmodule