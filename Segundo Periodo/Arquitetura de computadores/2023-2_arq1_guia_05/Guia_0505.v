module guia05(output s, input a, b);
    wire XNOR;
    xnor XNOR_(XNOR,a,b);
    nor NOR(s,XNOR,a);
endmodule

module main;
    reg a, b;
    reg [2:0] counter = 0;
    guia05 PORT(.s(s),.a(a),.b(b));
    initial begin
        for (counter = 0; counter < 4; counter++) begin
            a = counter[1];
            b = counter[0];
            #0;
            $display("%b    %d",counter[1:0], s);
        end
        $finish;
    end
endmodule