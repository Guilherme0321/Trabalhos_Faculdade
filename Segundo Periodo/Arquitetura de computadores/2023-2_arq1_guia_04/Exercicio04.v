module ex01(output s, input a, b, c);
    assign s = (a | b | ~c) & (a | ~b | ~c) & (~a | ~b | c) & (~a | ~b | ~c);
endmodule
module ex02(output s, input a, b, c);
    assign s = (a | b | c) & (~a | b | c) & (a | ~b | ~c) & (~a | ~b | ~c) & (~a | b | ~c);
endmodule
module ex03(output s, input a, b, c, d);
    assign s = (a | b | c | d) & (a | b | c | ~d) & (a | b | ~c | d) & (a | ~b | c | d) & (a | ~b | ~c | d) & (~a | b | c | d) & (~a | b | ~c | ~d) & (~a | ~b | c | ~d);
endmodule
module ex04(output s, input a, b, c, d);
    assign s = (a | b | c | ~d) & (a | b | ~c | d) & (a | ~b | c | d) & (a | ~b | ~c | d) & (~a | b | c | d) & (~a | b | c | ~d) & (~a | b | ~c | ~d);
endmodule
module ex05(output s, input a, b, c, d);
    assign s = (a | b | c | d) & (a | b | c | ~d) & (a | b | ~c | d) & (a | b | ~c | ~d) & (a | ~b | c | ~d) & (~a | b | ~c | ~d) & (~a | ~b | ~c | ~d);
endmodule
module Main;
    reg a, b, c, d;
    wire s, s2, s3, s4, s5;
    reg [4:0] count = 0;
    ex01 ref(.s(s),.a(a),.b(b),.c(c));
    ex02 ref2(.s(s2),.a(a),.b(b),.c(c));
    ex03 ref3(.s(s3),.a(a),.b(b),.c(c),.d(d));
    ex04 ref4(.s(s4),.a(a),.b(b),.c(c),.d(d));
    ex05 ref5(.s(s5),.a(a),.b(b),.c(c),.d(d));
    initial begin
        $display("Exercicio 4\n     A)");
        for (count = 0; count < 8 ; count++) begin
            a = count[2];
            b = count[1];
            c = count[0];
            #0;
            $display("      %d  %b  %d",count, count[2:0], s);
        end
        $display("\nExercicio 4\n     B)");
        for (count = 0; count < 8 ; count++) begin
            a = count[2];
            b = count[1];
            c = count[0];
            #0;
            $display("      %d  %b  %d",count, count[2:0], s2);
        end
        $display("\nExercicio 4\n     C)");

        for (count = 0; count < 16; count++) begin
            a = count[3];
            b = count[2];
            c = count[1];
            d = count[0];
            #0;
            $display("      %d  %b  %d",count, count[3:0], s3);

        end
        $display("\nExercicio 4\n     D)");
        for (count = 0; count < 16; count++) begin
            a = count[3];
            b = count[2];
            c = count[1];
            d = count[0];
            #0;
            $display("      %d  %b  %d",count, count[3:0], s4);
        end
        $display("\nExercicio 4\n     E)");

        for (count = 0; count < 16; count++) begin
            a = count[3];
            b = count[2];
            c = count[1];
            d = count[0];
            #0;
            $display("      %d  %b  %d",count, count[3:0], s5);
        end
        $finish;
    end
endmodule