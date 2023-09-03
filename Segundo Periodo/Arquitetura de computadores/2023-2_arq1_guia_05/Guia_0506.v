module guia06(output s, input a, b);
    wire NAND_AB, NAND_NANDAB_A, NAND_NANDAB_B;
    nand NAND1(NAND_AB,a,b);
    nand NAND2(NAND_NANDAB_A,NAND_AB,a);
    nand NAND3(NAND_NANDAB_B,NAND_AB,b);
    nand NAND(s,NAND_NANDAB_A,NAND_NANDAB_B);
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