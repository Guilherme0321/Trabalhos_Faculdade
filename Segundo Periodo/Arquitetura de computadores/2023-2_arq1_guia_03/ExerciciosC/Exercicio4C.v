module Exercicio04();

    reg [4:0] num1 = 8'b1010;
    reg [4:0] num2 = 8'b0110;
    reg [4:0] resul = 8'b0;

    function [4:0] eval(input [4:0] a, input [1:0] x, input [4:0] b);
        begin
            if (x == 2'b00) begin
                eval = ~(a - b)+1;
            end else if (x == 2'b01) begin
                eval = a + b;
            end else if (x == 2'b10) begin
                eval = a / b;
            end else begin
              eval = a * b;
            end
        end
    endfunction

    initial
    begin: main
        resul = eval(num2, 2'b00, num1);

        $display("%4b ", resul[3:0]);
        resul = eval(num2, 2'b01, num1);

        $display("%4b ", resul);
        resul = eval(num2, 2'b10, num1);

        $display("%4b ", resul);
        resul = eval(num2, 2'b11, num1);

        $display("%4b ", resul);
    end
endmodule
