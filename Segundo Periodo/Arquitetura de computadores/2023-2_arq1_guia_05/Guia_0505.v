module guia05(output s, input a, b);
    wire NOR_AB, NOR_NORAB_a, NOR_NORAB_b;
    nor NOR(NOR_AB,a,b);
    nor NOR1(NOR_NORAB_a,NOR_AB,a);
    nor NOR2(NOR_NORAB_b,NOR_AB,b);
    nor NOR3(s, NOR_NORAB_a, NOR_NORAB_b);
endmodule
module main;
    reg a, b;
    reg [2:0] counter = 0;
    wire s;
    guia05 GUIA(.s(s),.a(a),.b(b));
    initial begin
        for (counter = 0; counter < 4; counter++) begin
            a = counter[1];
            b = counter[0];
            #0;
            $display("%b      %d", counter[1:0],s);
        end
        $finish;
    end
endmodule