module f7 ( output s, input a, input b, input e, input e1);
    wire XOR01, XOR02, XNOR01, XNOR02, XNOR_XOR12;
   
        xor XOR(XOR01,a,e1);
        xor XOR1(XOR02,e,b);

        xnor XNOR(XNOR01,a,e1);
        xnor XNOR1(XNOR02,e,b);

        xnor XNOR2(XNOR_XOR12,XOR01,XOR02);

        xnor XNOR3(s,XNOR01,XNOR02,XNOR_XOR12);

endmodule

module test_f7;
    reg x;
    reg y;
    reg s, s1;
    reg [4:0] counter = 0;
    wire z;
    f7 modulo (.s(z),.a(x),.b(y),.e(s),.e1(s1));

    
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