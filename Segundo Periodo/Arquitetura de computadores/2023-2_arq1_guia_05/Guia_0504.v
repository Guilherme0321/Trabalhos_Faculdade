module guia04 (output s, input a, b);
    wire ab, ab_b, abb_ab;
    nand NAND1(ab,a,b);
    nand NAND2(ab_b,ab,b);
    nand NAND3(abb_ab,ab_b,ab);
    nand NAND4(s,abb_ab, ab);
endmodule

module main;
    reg a, b;
    wire s;
    reg [2:0] counter = 0;
    guia04 Port(.s(s),.a(a),.b(b));
    initial begin
        for (counter = 0; counter < 4; counter++) begin
            a = counter[1];
            b = counter[0];
            #0
            $display("%b   %d",counter[1:0],s);
        end
        $finish;
    end
endmodule