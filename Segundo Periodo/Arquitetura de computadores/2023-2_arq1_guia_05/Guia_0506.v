module guia06(output s, input a, b);
    wire OR;
    xor XOR(OR,a,b);
    nand NAND(s,OR,b);
endmodule

module main;
    reg a, b;
    wire s;
    reg [2:0] counter = 0;
    guia06 PORT(.s(s),.a(a),.b(b));
    initial begin
        for(counter = 0; counter < 4; counter++)begin
            a = counter[1];
            b = counter[0];
            #0;
            $display("%b     %d",counter[1:0],s);
        end
        $finish;
    end
endmodule