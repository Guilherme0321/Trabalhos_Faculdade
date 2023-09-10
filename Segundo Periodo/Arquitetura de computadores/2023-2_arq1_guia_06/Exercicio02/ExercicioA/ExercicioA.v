module naoResumido(output s, input a, b, c);
    assign s = (~a | b | c) & (~a | b | ~c) & (~a | ~b | ~c);
endmodule

module resumido(output s, input a, b, c);
    assign s = (~a | ~c) & (~a | b | c);
endmodule

module main;
    reg a, b, c;
    wire s, s2;
 
    reg [3:0] counter = 0;
    integer tabela[7:0][2:0]; //declaração da tabela

    naoResumido exe1(.s(s),.a(a),.b(b),.c(c));
    resumido exe1r(.s(s2),.a(a),.b(b),.c(c));
    initial begin
        for (integer i = 0; i < 8; i++) begin
            for (integer j = 0; j < 2; j++) begin // preenchimento da tabela
                a = counter[2];
                b = counter[1];
                c = counter[0];
                #0;
                tabela[i][j] = s;
                counter++;
            end
        end
        // montagem da tabela
        $display("  -------------");
        $display("  |   |%2d |%2d |",counter[1:0],counter+1);
        $display("  -------------");
        for (counter = 0; counter < 4; counter++) begin
            $display("  |%2b |%2d |%2d |", counter[1:0], tabela[counter][0], tabela[counter][1]);
            $display("  -------------");
        end
        $display("\n       (a' | b | c) & (a' | b | c') & (a' | b' | c')   (a' | c') & (a' | b | c)");
        for (counter = 0; counter < 8; counter++) begin
            a = counter[2];
            b = counter[1];
            c = counter[0];
            #0;
            $display("%b      %20d         %28d", counter[2:0], s, s2);
        end
        $finish;

    end
endmodule