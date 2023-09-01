module guia04 (output s, input a, b);
    wire not_A,notAll;
    not NOT(not_A,a);
    nand NAND(notAll,not_A,b);
    not NOT1(s,notAll);
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