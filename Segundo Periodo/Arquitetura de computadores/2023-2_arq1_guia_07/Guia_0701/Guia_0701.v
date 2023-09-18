module f7 ( output s, output s1, input a, input b, input selected);
    wire sa, sb, sc, sd;

    and AND1(sa,a,selected);
    and AND2(sb,b,selected);
    and AND3(s,sa,sb);
    
    nand NAND(sc,a,selected);
    nand NAND1(sd,b,selected);
    nand NAND2(s1,sc,sd);
    
endmodule

module test_f7;
// ------------------------- definir dados
    reg x;
    reg y;
    reg s;
    reg [2:0] counter = 0;
    wire z, z1;
    f7 modulo (.s(z),.s1(z1),.a(x),.b(y),.selected(s));

    
    initial
    begin : main
        $display("X Y selected and nand");
        // projetar testes do modulo
        $display("Selected = 0");

        for (counter = 0;counter <= 3 ; counter++) begin
            x = counter[1]; y = counter[0]; s = 1'b0;
            #1;
            $display("%4b %4b %4b %4b %4b", x, y, s, z, z1);
        end
            $display("Selected = 1");

        for (counter = 0;counter <= 3 ; counter++) begin
            x = counter[1]; y = counter[0]; s = 1'b1;
            #1;
            $display("%4b %4b %4b %4b %4b", x, y, s, z, z1);
        end
        counter = 0;

        $finish;
    end
endmodule