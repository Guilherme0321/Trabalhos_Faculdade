module Resumido(output s, input a, b, c);
    wire NOR1, NOR2, NOR3, NOR4, NOR5, NOR6, NOR7, NOR8;
    wire notNOR1, notNOR2, notNOR3, notNOR4, notNOR5, notNOR6, notNOR7, notNOR8;
    nor NOR000(NOR1,a,b,c);
    nor NOR001(NOR2,a,b,~c);
    nor NOR010(NOR3,a,~b,c);
    nor NOR011(NOR4,a,~b,~c);
    nor NOR100(NOR5,~a,b,c);
    nor NOR101(NOR6,~a,b,~c);
    nor NOR110(NOR7,~a,~b,c);
    nor NOR111(NOR8,~a,~b,~c);

    nor NOR2_(notNOR1,NOR1);
    nor NOR21(notNOR2,NOR2);
    nor NOR212(notNOR3,NOR3);
    nor NOR211(notNOR4,NOR4);
    nor NOR12(notNOR5,NOR5);
    nor NOR121(notNOR6,NOR6);
    nor NOR112(notNOR7,NOR7);
    nor NOR11221(notNOR8,NOR8);

    nor finalNOR(s, notNOR1, notNOR2, notNOR3, notNOR4, notNOR5, notNOR6, notNOR7, notNOR8);
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
            $display("%d %d", counter,s);
        end
        $finish;

    end
endmodule