module f7 ( output s, input a, input b, input e, input e1);
    wire ANDab, NANDab, ORab,NORab, RESUL_and, RESUL_nand, RESUL_or, RESUL_nor;
   
        and AND(ANDab,a,b);
        nand NAND(NANDab,a,b);
        or OR(ORab,a,b);
        nor NOR(NORab,a,b);

        and AND01(RESUL_and,~e,~e1,ANDab);
        and AND02(RESUL_nand,~e,e1,NANDab);
        and AND03(RESUL_or,e,~e1,ORab);
        and AND04(RESUL_nor,e,e1,RESUL_nor);

        or OR01(s,RESUL_and,RESUL_nand,RESUL_nor,RESUL_or);
    
endmodule

module test_f7;
    reg x;
    reg y;
    reg s, s1;
    reg [2:0] counter = 0, i = 0;
    wire z;
    f7 modulo (.s(z),.a(x),.b(y),.e(s),.e1(s1));

    
    initial
    begin : main

        for(i = 0; i < 4; i++)begin
            $display("   X    Y selected or");
            for (counter = 0;counter < 4 ; counter++) begin
                x = counter[1]; y = counter[0]; s = i[1]; s1 = i[0];
                #1;
                $display("%4b %4b %4b%b %4b", x, y, s, s1, z);
            end
            $display("\n");
        end
        $finish;
    end
endmodule