module naoResumido(output s, input a, b, c, d);
    assign s = (~a & ~b & ~c & ~d) | (~a & ~b & ~c & d) | (~a & ~b & c & ~d) | (~a & ~b & c & d) | (~a & b & ~c & ~d) | (~a & b & ~c & d) | (~a & b & c & ~d) | (~a & b & c & d) | (a & ~b & ~c & ~d) | (a & ~b & ~c & d) | (a & ~b & c & ~d) | (a & ~b & c & d) | (a & b & ~c & ~d) | (a & b & ~c & d) | (a & b & c & ~d) | (a & b & c & d); 
endmodule

module main;
    reg a, b, c, d;
    wire s;
 
    reg [4:0] counter = 0;

    naoResumido exe1(.s(s),.a(a),.b(b),.c(c),.d(d));
    initial begin
        for (counter = 0; counter < 16; counter++) begin
            a = counter[3];
            b = counter[2];
            c = counter[1];
            d = counter[0];
            #0;
            $display("%d", s);
        end
        $finish;

    end
endmodule