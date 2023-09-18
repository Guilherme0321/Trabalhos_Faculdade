module f7 ( output s, input a, input b, input selected);
    wire orab, norab, nor01, nor02,resul,resul01;
   
        or OR(orab,a,b);
        nor NOR1(norab,a,b);
        nor NOR02(nor01,norab,norab);
        nor NOR03(nor02,orab,orab);
        nor NOR04(resul,nor01,selected);
        nor NOR05(resul01,nor02,selected);
        or OR02(s,resul,resul01);
    
endmodule

module test_f7;
// ------------------------- definir dados
    reg x;
    reg y;
    reg s;
    reg [2:0] counter = 0;
    wire z;
    f7 modulo (.s(z),.a(x),.b(y),.selected(s));

    
    initial
    begin : main
        $display("X Y selected or");
        // projetar testes do modulo
        $display("Selected = 0");
        s = 1'b0;
        for (counter = 0;counter <= 3 ; counter++) begin
            x = counter[1]; y = counter[0]; s = 1'b0;
            #1;
            $display("%4b %4b %4b %4b", x, y, s, z);
        end
            $display("Selected = 1");
        $display("X Y selected nor");
        s = 1'b1;
        for (counter = 0;counter <= 3 ; counter++) begin
            x = counter[1]; y = counter[0]; 
            #1;
            $display("%4b %4b %4b %4b", x, y, s, z);
        end
        counter = 0;

        $finish;
    end
endmodule