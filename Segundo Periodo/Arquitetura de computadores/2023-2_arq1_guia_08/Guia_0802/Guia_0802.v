module f7 ( output [5:0] s, input [1:0] a, input [1:0] b, input [1:0] c, input [1:0] d, input [1:0] e);
    wire AND1, AND2, AND3, AND4, AND5, AND6, AND7, AND8, AND9, AND10;
    wire XOR1, XOR2, XOR3, XOR4, XOR5;
    wire OR1, OR2, OR3, OR4, OR5, OR6, OR7, OR8, OR9, OR10;

    wire v1, v2, v3, v4;

    wire NOT1, NOT2, NOT3, NOT4, NOT5, NOT6, NOT7, NOT8, NOT9, NOT10;


    not NOT(NOT1,e[1]);
    and AND00(AND1,NOT1,e[0]);
    xor XOR00(XOR1,e[1],e[0]);
        not NOR01(NOT2,XOR1);
        and AND01(AND2,NOT2,0);
        xor XOR01(s[0], XOR1,0);
            or OR(v1,AND1,AND2);

    not NOT1001(NOT3,d[1]);
    and AND11(AND3,NOT3,d[0]);
    xor XOR11(XOR2,d[1],d[0]);
        not NOT11(NOT4,XOR2);
        and AND02(AND4,NOT4,v1);
        xor XOR02(s[1], XOR2,v1);
            or OR01(v2,AND3,AND4);

    not NOT100(NOT5,c[1]);
    and AND22(AND5,NOT5,c[0]);
    xor XOR22(XOR3,c[1],c[0]);
        not NOT101(NOT6,XOR3);
        and AND03(AND6,NOT6,v2);
        xor XOR03(s[2], XOR3,v2);
            or OR02(v3,AND5,AND6);

    not NOT110(NOT7,b[1]);
    and AND33(AND7,NOT7,b[0]);
    xor XOR33(XOR4,b[1],b[0]);
        not NOT111(NOT8,XOR4);
        and AND04(AND8,NOT8,v3);
        xor XOR04(s[3], XOR4,v3);
            or OR03(v4,AND7,AND8);

    not NOT1100(NOT9,a[1]);
    and AND44(AND9,NOT9,a[0]);
    xor XOR44(XOR5,a[1],a[0]);
        not NOT1101(NOT10,XOR5);
        and AND05(AND10,NOT10,v4);
        xor XOR05(s[4], XOR5,v4);
            or OR04(s[5],AND9,AND10);

endmodule

module test_f7;
    reg [1:0] a;
    reg [1:0] b;
    reg [1:0] c, d, e;
    reg [6:0] counter = 0, count = 0;
    wire [5:0] z;
    f7 modulo (.s(z),.a(a),.b(b),.c(c),.d(d),.e(e));

    
    initial
    begin : main
        for (counter = 0; counter <= 31; counter++) begin
            for (count = 0;count <= 31 ; count++) begin
                a[1] = counter[4]; b[1] = counter[3]; c[1] = counter[2]; d[1] = counter[1]; e[1] = counter[0];
                a[0] = count[4]; b[0] = count[3]; c[0] = count[2]; d[0] = count[1]; e[0] = count[0];
                #0;
                $display("%d - %d = %d",counter,count,z);
            end
            $display("\n");
        end
        $finish;
    end
endmodule