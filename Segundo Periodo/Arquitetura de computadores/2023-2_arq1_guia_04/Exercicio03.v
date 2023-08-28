module SoP (output s, input x, y, z);
    assign s = (~x & ~y & ~z) | (~x & ~y & z) | (~x & y & ~z) | (~x & y & z) | (x & ~y & ~z);
endmodule

module SOP ( output s, input a,b,c,d);
    assign s = (~a & ~b & ~c & ~d) | (~a & ~b & ~c & d) | (~a & ~b & c & ~d) | (~a & ~b & c & d) | (~a & b & ~c & ~d) | (~a & b & ~c & d) | (~a & b & c & ~d) | (~a & b & c & d) | (a & ~b & ~c & ~d) | (a & ~b & ~c & d);
endmodule

module Main;
    reg x, y, z;
    reg a, b, c, d;
    wire s,r;

    SoP SoP_Inst(.s(s), .x(x), .y(y), .z(z));
    SOP sop_instancia(.s(r),.a(a),.b(b),.c(c),.d(d));
    initial begin
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        #10;
        $display("s = %d", s);
        
        a = 1;
        b = 0;
        c = 0;
        d = 0;
        
        $display("s = %d", s);

        a = 0;
        b = 1;
        c = 0;
        d = 0;
        
        $display("s = %d", s);

        a = 1;
        b = 1;
        c = 0;
        d = 0;
        
        $display("s = %d", s);

        a = 0;
        b = 0;
        c = 1;
        d = 0;
        
        $display("s = %d", s);

        a = 1;
        b = 0;
        c = 1;
        d = 0;
        
        $display("s = %d", s);

        a = 0;
        b = 1;
        c = 1;
        d = 0;
        
        $display("s = %d", s);

        a = 1;
        b = 1;
        c = 1;
        d = 0;
        
        $display("s = %d", s);
        $finish;
    end
endmodule
