module f7 ( output s, input a, input b, input c, input d);
    wire um, dois,tres,quatro,cinco,seis,sete,oito;
    wire notA, notB, notC, notD, restado01, restado02;
    wire notResul01;
    not NOT(notA,a);
    not NOT1(notB,b);
    not NOT2(notC,c);
    not NOT3(notD,d);

    and AND(um,notA,notB,d);
    and AND1(dois,notA,c,notD);
    and AND2(tres,a,notB,c,d);
    and AND3(quatro,notA,b,c,d);    
   
    or OR(restado01,um,dois,tres,quatro);

    and AND4(cinco,a,notB,notC);
    and AND5(seis,notA,b,notC,notD);
    and AND6(sete,a,b,notC);
    and AND7(oito,a,b,c,notD);   

    or OR1(restado02,cinco,seis,sete,oito);
    not NOT10(notResul01,restado01);
    and AND10(s,restado02,notResul01);

endmodule

module test_f7;
    reg x;
    reg y;
    reg s, s1;
    reg [4:0] counter = 0;
    wire z;
    f7 modulo (.s(z),.a(x),.b(y),.c(s),.d(s1));

    
    initial
    begin : main
        $display("   X    Y selected or");
        for (counter = 0;counter < 16 ; counter++) begin
            x = counter[3]; y = counter[2]; s = counter[1]; s1 = counter[0];
            #0;
            $display("%4d %4d %4d %4d %4d", x, y, s, s1, z);
        end
            $display("\n");
        $finish;
    end
endmodule