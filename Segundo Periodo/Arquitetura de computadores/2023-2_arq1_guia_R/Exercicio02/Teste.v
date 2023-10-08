module f ( output s, input a, input b, input c );
wire w1, w2, w3, w4;
not NOT_1 (w1, b);
not NOT_2 (w2, c);
and AND_1 (w3, a, w2);
and AND_2 (w4, a, w1, c);
or OR__1 (s, w3 ,w4);
endmodule // s = f (a,b,c)

module main;
    reg a, b, c;
    wire s;
    reg [4:0] counter = 0;
    f F(.s(s),.a(a),.b(b),.c(c));
    initial begin
        for (counter = 0;counter < 16 ; counter++) begin
            a = counter[2];
            b = counter[1];
            c = counter[0];
            #0;
            $display("%d", s);
        end
        $finish;
    end
endmodule