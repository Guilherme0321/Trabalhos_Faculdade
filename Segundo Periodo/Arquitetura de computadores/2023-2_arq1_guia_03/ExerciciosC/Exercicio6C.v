module Exercicio6();    
    reg [7:0] byte01 = 8'b001111;
    reg [7:0] resultado = 8'b0;
    function [7:0] complement1(input [7:0] num);
        begin
            complement1 = ~num +1;
        end
        
    endfunction
initial

    begin : main
        resultado = complement1(byte01);
        $display("%b", resultado);

    end
endmodule