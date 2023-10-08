module exer03 ( output s, input a, input b );
    wire nor01, nor02, nand01, nand02;
    nor NOR(nor01,a,a);
    nand NAND(nand01,nor01,b);
    nor NOR1(nor02,a,a);
    nand NAND1(nand02,nor02,b);
    nand NANDfinal(s,nand01,nand02);
endmodule 

module main;
    reg a, b;
    wire s;
    reg [2:0] counter = 0;
    exer03 exer3(.s(s),.a(a),.b(b));
    initial begin
        for (counter = 0;counter < 4 ; counter++) begin
            a = counter[1];
            b = counter[0];
            #0;
            $display("%d", s);
        end
        $finish;
    end
endmodule