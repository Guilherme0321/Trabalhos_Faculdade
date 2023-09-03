module guia08(output s, input a, b);
    wire AB, AB_A, ABA_AB;
    nand NAND(AB,a,b);
    nand NAND2(AB_A,AB,a);
    nand NAND3(ABA_AB,AB_A,AB);
    nand NAND4(s,AB,ABA_AB);
endmodule

module main;
    reg a, b;
    wire s;
    reg [2:0] counter = 0;
    guia08 guia(.s(s),.a(a),.b(b));
    initial begin
        for (counter = 0; counter < 4; counter++) begin
            a = counter[1];
            b = counter[0];
            #0;
            $display("%b    %d",counter[1:0],s);
        end
        $finish;
    end
endmodule