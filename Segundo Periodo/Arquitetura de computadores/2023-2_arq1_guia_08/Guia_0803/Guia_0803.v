module f7 (output saida,output [4:0] s, input [1:0] a, input [1:0] b, input [1:0] c, input [1:0] d, input [1:0] e);

    xnor XNOR01(s[0],e[0],e[1]);
    xnor XNOR10(s[1],d[0],d[1]);
    xnor XNOR11(s[2],c[0],c[1]);
    xnor XNOR100(s[3],b[0],b[1]);
    xnor XNOR0101(s[4],a[0],a[1]);

    and AND(saida,s[0],s[1],s[2],s[3],s[4]);

endmodule

module test_f7;
    reg [1:0] a;
    reg [1:0] b;
    reg [1:0] c, d, e;
    reg [4:0] counter = 0, count = 0;
    wire [4:0] z;
    wire resul;
    f7 modulo (.saida(resul),.s(z),.a(a),.b(b),.c(c),.d(d),.e(e));

    
    initial
    begin : main
    $display("num01 num02 -> comparação_de_cada_bit resultado");
        for (counter = 0; counter <= 8; counter++) begin
            for (count = 0;count <= 8; count++) begin
                a[1] = counter[4]; b[1] = counter[3]; c[1] = counter[2]; d[1] = counter[1]; e[1] = counter[0];
                a[0] = count[4]; b[0] = count[3]; c[0] = count[2]; d[0] = count[1]; e[0] = count[0];
                #0;
                $display("%b == %b -> %b %d",counter,count,z,resul);
            end
            $display("\n");
        end
        $finish;
    end
endmodule