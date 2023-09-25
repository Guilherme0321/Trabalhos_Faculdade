module f7 ( output [5:0] s, input  a, input  b, input  c, input  d, input  e);
    wire AND1, AND2, AND3, AND4, AND5, AND6, AND7, AND8, AND9, AND10;
    wire XOR1, XOR2, XOR3, XOR4, XOR5;
    wire OR1, OR2, OR3, OR4, OR5, OR6, OR7, OR8, OR9, OR10;

    wire v1, v2, v3, v4;
    wire zero = 1;
    and AND00(AND1,e,zero);
    xor XOR00(XOR1,e,zero);
        and AND01(AND2,XOR1,zero);
        xor XOR01(s[0], XOR1,zero);
            or OR(v1,AND1,AND2);

    and AND11(AND3,d,zero);
    xor XOR11(XOR2,d,zero);
        and AND02(AND4,XOR2,v1);
        xor XOR02(s[1], XOR2,v1);
            or OR01(v2,AND3,AND4);

    and AND22(AND5,c,zero);
    xor XOR22(XOR3,c,zero);
        and AND03(AND6,XOR3,v2);
        xor XOR03(s[2], XOR3,v2);
            or OR02(v3,AND5,AND6);
    
    and AND33(AND7,b,zero);
    xor XOR33(XOR4,b,zero);
        and AND04(AND8,XOR4,v3);
        xor XOR04(s[3], XOR4,v3);
            or OR03(v4,AND7,AND8);
    
    and AND44(AND9,a,zero);
    xor XOR44(XOR5,a,zero);
        and AND05(AND10,XOR5,v4);
        xor XOR05(s[4], XOR5,v4);
            or OR04(s[5],AND9,AND10);

endmodule

module test_f7;
    reg a;
    reg b;
    reg c, d, e;
    reg [6:0] counter = 0, count = 0;
    wire [5:0] z;
    f7 modulo (.s(z),.a(a),.b(b),.c(c),.d(d),.e(e));

    
    initial
    begin : main
        for (counter = 0;counter <= 31 ; counter++) begin
            a = counter[4]; b = counter[3]; c = counter[2]; d = counter[1]; e = counter[0];
            
            #0;
            $display("%d == -%d %d",counter,z,~counter[5:0]);
        end
        $display("\n");
        
        $finish;
    end
endmodule