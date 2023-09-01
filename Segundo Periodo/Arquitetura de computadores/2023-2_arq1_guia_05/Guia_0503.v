module guia03(output s, input a,b);
    wire not_A, not_B;
    not NOT(not_A,a);
    not NOT1(not_B,b);
    nor NOR(s,not_A,not_B);
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