module Exercicio7 ();

    reg [7:0] num1 = 8'b111100;
    reg [7:0] result = 8'b0;

    function [7:0] complement2(input [7:0] x);
        begin
            complement2 = ~(x)+2;
        end
        
    endfunction

    initial
        begin : main
            result = complement2(num1);
            $display("%b", result);
        end
endmodule