module Guia_04();
    reg [1:0] booleans[0:2];
    integer counter = 0, resul;
    function reg tabela (input a, input b, input c);
        begin
            tabela = ~a | (~b & ~c);
            $display("%d x',y',z' %d,%d,%d %b x'+(y'*z')",counter,~a,~b,~c,tabela);
            counter++;
        end
    endfunction
    function reg ex01 (input a, b, c);
        begin
            ex01 = a & ~(~b | ~c);
            $display("%d x,y',z' %d,%d,%d %b x'+(y'*z')",counter,a,~b,~c,ex01);
            counter++;
        end
    endfunction
    function reg ex02 (input a, b, c);
        begin
            ex02 = c & ~(~b | ~a);
            $display("%d x,y',z' %d,%d,%d %b x'+(y'*z')",counter,~a,~b,c,ex02);
            counter++;
        end
    endfunction
    function reg ex03 (input a, b, c);
        begin
            ex03 = ~c & ~(~b & ~a);
            $display("%d x,y',z' %d,%d,%d %b x'+(y'*z')",counter,~a,~b,~c,ex03);
            counter++;
        end
    endfunction
    function reg ex04 (input a, b, c);
        begin
            ex04 = c & ~(~b & a);
            $display("%d x,y',z' %d,%d,%d %b x'+(y'*z')",counter,a,~b,c,ex04);
            counter++;
        end
    endfunction
    initial 
        begin
            $display("  Preparacao do codigo\n");
            resul = tabela(0,0,0);
            resul = tabela(0,0,1);
            resul = tabela(0,1,0);
            resul = tabela(0,1,1);
            resul = tabela(1,0,0);
            resul = tabela(1,0,1);
            resul = tabela(1,1,0);
            resul = tabela(1,1,1);
            $display("\n  Exercicio 01\n");
            counter = 0;
            resul = ex01(0,0,0);
            resul = ex01(0,0,1);
            resul = ex01(0,1,0);
            resul = ex01(0,1,1);
            resul = ex01(1,0,0);
            resul = ex01(1,0,1);
            resul = ex01(1,1,0);
            resul = ex01(1,1,1);
            $display("\n  Exercicio 02\n");
            counter = 0;
            resul = ex02(0,0,0);
            resul = ex02(0,0,1);
            resul = ex02(0,1,0);
            resul = ex02(0,1,1);
            resul = ex02(1,0,0);
            resul = ex02(1,0,1);
            resul = ex02(1,1,0);
            resul = ex02(1,1,1);
            $display("\n  Exercicio 03\n");
            counter = 0;
            resul = ex03(0,0,0);
            resul = ex03(0,0,1);
            resul = ex03(0,1,0);
            resul = ex03(0,1,1);
            resul = ex03(1,0,0);
            resul = ex03(1,0,1);
            resul = ex03(1,1,0);
            resul = ex03(1,1,1);
            $display("\n  Exercicio 04\n");
            counter = 0;
            resul = ex04(0,0,0);
            resul = ex04(0,0,1);
            resul = ex04(0,1,0);
            resul = ex04(0,1,1);
            resul = ex04(1,0,0);
            resul = ex04(1,0,1);
            resul = ex04(1,1,0);
            resul = ex04(1,1,1);

        end
endmodule