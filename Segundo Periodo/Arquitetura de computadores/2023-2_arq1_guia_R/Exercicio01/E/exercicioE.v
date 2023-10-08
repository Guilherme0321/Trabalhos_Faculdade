module Resumido(output s, input a, b, c);
    wire NAND1, NAND2, NAND3, NAND4, NAND5, NAND6, NAND7, NAND8;
    wire notNAND1, notNAND2, notNAND3, notNAND4, notNAND5, notNAND6, notNAND7, notNAND8;
    nand NAND000(NAND1,a,b,c);
    nand NAND001(NAND2,a,b,~c);
    nand NAND010(NAND3,a,~b,c);
    nand NAND011(NAND4,a,~b,~c);
    nand NAND100(NAND5,~a,b,c);
    nand NAND101(NAND6,~a,b,~c);
    nand NAND110(NAND7,~a,~b,c);
    nand NAND111(NAND8,~a,~b,~c);

    nand NAND2_(notNAND1,NAND1);
    nand NAND21(notNAND2,NAND2);
    nand NAND212(notNAND3,NAND3);
    nand NAND211(notNAND4,NAND4);
    nand NAND12(notNAND5,NAND5);
    nand NAND121(notNAND6,NAND6);
    nand NAND112(notNAND7,NAND7);
    nand NAND11221(notNAND8,NAND8);

    nand finalNAND(s, notNAND1, notNAND2, notNAND3, notNAND4, notNAND5, notNAND6, notNAND7, notNAND8);
endmodule

module main;
    reg a, b, c;
    wire s;
 
    reg [4:0] counter = 0;

    Resumido exe1(.s(s),.a(a),.b(b),.c(c));
    initial begin
        for (counter = 0; counter < 16; counter++) begin
            a = counter[2];
            b = counter[1];
            c = counter[0];
            #0;
            $display("%d", s);
        end
        $finish;

    end
endmodule