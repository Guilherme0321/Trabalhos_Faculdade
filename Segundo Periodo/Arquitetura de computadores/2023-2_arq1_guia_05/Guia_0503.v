module guia03(output s, input a,b);
    wire not_A, not_B, norAB;
    nor NOR(not_A,a,a);
    nor NOR1(not_B,b,b);
    nor NOR2(norAB,not_A,not_B);
    nor NOR3(s,norAB,norAB);
endmodule

module main;
    reg a, b;
    reg [2:0] counter = 0;
    wire s;
    guia03 port(.s(s),.a(a),.b(b));
    initial begin
        for (counter = 0; counter < 4; counter++) begin
            a = counter[1];
            b = counter[0];
            #0
            $display("%b   %d",counter[1:0], s);
        end
        $finish;
    end
endmodule