module naoResumido(output s, input a, b, c, d);
    assign s = (a & b & c & ~d) | (a & b & ~c & d) | (a & ~b & ~c & d) | (~a & b & ~c & d) | (~a & ~b & c & ~d) | (~a & b & ~c & ~d) | (~a & b & c & d);
endmodule

module resumido(output s, input a, b, c, d);
    assign s = (~a & b & ~c) | (a & ~c & d) | (~a & b & c & d) | (a & b & c & ~d) | (~a & ~b & c & ~d);
endmodule

module main;
    reg a, b, c, d;
    wire s, s2;
    reg [4:0] counter = 0;
    reg [1:0] substCounter[4:0];
    integer tabela[7:0][4:0];

    naoResumido exe1(.s(s),.a(a),.b(b),.c(c),.d(d));
    resumido exe1r(.s(s2),.a(a),.b(b),.c(c),.d(d));
    initial begin
        for (integer i = 0; i < 16; i++) begin
            for (integer j = 0; j < 4; j++) begin
                a = counter[3];
                b = counter[2];
                c = counter[1];
                d = counter[0];
                #0;
                tabela[i][j] = s;
                counter++;
            end
        end
        for (integer h = 0; h < 4; h++) begin
            substCounter[h] = h;
        end
        
        $display("  ---------------------");
        $display("  |   |%2b |%2b |%2b |%2b |",substCounter[0],substCounter[1],substCounter[2],substCounter[3]);
        $display("  ---------------------");
        for (counter = 0; counter < 4; counter++) begin
            $display("  |%2b |%2d |%2d |%2d |%2d |", counter[1:0], tabela[counter][0], tabela[counter][1], tabela[counter][2], tabela[counter][3]);
            $display("  ---------------------");
        end
        $display("\n   (a.b.c.d')+(a.b.c'.d)+(a.b'.c'.d)+(a'.b.c'.d)+(a'.b'.c.d')+(a'.b.c'.d')+(a'.b.c.d)       (a'.b.c')+(a.c'.d)+(a'.b.c.d)+(a.b.c.d')+(a'.b'.c.d')");
        for (counter = 0; counter < 16; counter++) begin
            a = counter[3];
            b = counter[2];
            c = counter[1];
            d = counter[0];
            #0;
            $display("%b      %20d         %50d", counter[3:0], s, s2);
        end
        $finish;

    end
endmodule