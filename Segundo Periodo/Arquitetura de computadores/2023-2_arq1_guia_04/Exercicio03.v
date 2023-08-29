module exA (output s, input x, y, z);
    assign s = (~x & y & ~z) | (~x & y & z) | (x & y & ~z) | (x & y & z);
endmodule
module exB (output s, input x, y, z);
    assign s = (~x & ~y & z) | (~x & y & z) | (x & ~y & z) | (x & y & z);
endmodule

module exC (output s, input a,b,c,d);
    assign s = (~a & ~b & ~c & d) | (~a & ~b & c & d) | (~a & b & ~c & ~d) | (~a & b & c & ~d) | (a & ~b & ~c & d) | (a & b & ~c & ~d) | (a & b & ~c & d);
endmodule

module exD (output s, input a,b,c,d);
    assign s = (~a & ~b & ~c & d) | (~a & ~b & c & ~d) | (~a & b & ~c & d) | (~a & b & c & ~d) | (a & ~b & ~c & ~d) | (a & ~b & c & ~d) | (a & b & ~c & ~d);
endmodule

module exE (output s, input a,b,c,d);
    assign s = (~a & ~b & ~c & ~d) | (~a & ~b & c & ~d) | (~a & ~b & c & d) | (~a & b & c & d) | (a & ~b & ~c & d) | (a & b & ~c & d);
endmodule

module Main;
    reg x1, y1, z1,x2,y2,z2;
    reg a, b, c, d, a4,b4,c4,d4, a5,b5,c5,d5;
    wire s,s2,r, s4 , s5;
    reg [2:0] count = 0;
    reg [4:0] counter4 = 0;
    exA SoP_Inst(.s(s), .x(x1), .y(y1), .z(z1));
    exB exB(.s(s2), .x(x2), .y(y2), .z(z2));
    exC sop_instancia(.s(r),.a(a),.b(b),.c(c),.d(d));
    exD exd(.s(s4),.a(a4),.b(b4),.c(c4),.d(d4));
    exE exe(.s(s5),.a(a5),.b(b5),.c(c5),.d(d5));
    initial begin
        $display("Exercicio 03\n    A)");
        x1 = 0;
        y1 = 0;
        z1 = 0;
        #0;
        $display("%d   %b    %d ", count, count , s);
        count++;
        x1 = 0;
        y1 = 0;
        z1 = 1;
        #0;
        $display("%d   %b    %d ", count, count , s); 
        count++;
        x1 = 0;
        y1 = 1;
        z1 = 0;
        #0;
        $display("%d   %b    %d ", count, count , s);// 2
        count++;
        x1 = 0;
        y1 = 1;
        z1 = 1;
        #0;
        $display("%d   %b    %d ", count, count , s);// 3
        count++;
        x1 = 1;
        y1 = 0;
        z1 = 0;
        #0;
        $display("%d   %b    %d ", count, count , s);
        count++;
        x1 = 1;
        y1 = 0;
        z1 = 1;
        #0;
        $display("%d   %b    %d ", count, count , s);
        count++;
        x1 = 1;
        y1 = 1;
        z1 = 0;
        #0;
        $display("%d   %b    %d ", count, count , s);// 6
        count++;
        x1 = 1;
        y1 = 1;
        z1 = 1;
        #0;
        $display("%d   %3b    %d ", count, count , s);// 7
        count++;

        $display("Exercicio 03\n    B)");
        count = 0;
        x2 = 0;
        y2 = 0;
        z2 = 0;
        #0;
        $display("%d   %b    %d ", count, count , s2);
        count++;
        x2 = 0;
        y2 = 0;
        z2 = 1;
        #0;
        $display("%d   %b    %d ", count, count , s2); 
        count++;
        x2 = 0;
        y2 = 1;
        z2 = 0;
        #0;
        $display("%d   %b    %d ", count, count , s2);// 2
        count++;
        x2 = 0;
        y2 = 1;
        z2 = 1;
        #0;
        $display("%d   %b    %d ", count, count , s2);// 3
        count++;
        x2 = 1;
        y2 = 0;
        z2 = 0;
        #0;
        $display("%d   %b    %d ", count, count , s2);
        count++;
        x2 = 1;
        y2 = 0;
        z2 = 1;
        #0;
        $display("%d   %b    %d ", count, count , s2);
        count++;
        x2 = count[2];
        y2 = count[1];
        z2 = count[0];
        #0;
        $display("%d   %b    %d ", count, count , s2);// 6
        count++;
        x2 = count[2];
        y2 = count[1];
        z2 = count[0];
        #0;
        $display("%d   %3b    %d ", count, count , s2);// 7
        count++;
        $display("Exercicio 03\n    C)");

        for (counter4 = 8'b00000;counter4 <= 8'b1111 ; counter4++) begin    
            a = counter4[3];
            b = counter4[2];
            c = counter4[1];
            d = counter4[0];
            #0;
            $display("%d  %4b   %d",counter4,counter4[3:0], r);
        end
        counter4++;
        

        $display("Exercicio 03\n    D)");

        for (counter4 = 0;counter4 <= 15; counter4++) begin
            a4 = counter4[3];
            b4 = counter4[2];
            c4 = counter4[1];
            d4 = counter4[0];
            #0;
            $display("%d  %4b   %d",counter4,counter4[3:0], s4);
        end
        counter4++;

        $display("Exercicio 03\n    E)");
        for (counter4 = 0;counter4 <= 15; counter4++) begin
            a5 = counter4[3];
            b5 = counter4[2];
            c5 = counter4[1];
            d5 = counter4[0];
            #0;
            $display("%d  %4b   %d",counter4,counter4[3:0], s5);
        end
        counter4++;

        $finish;
    end
endmodule
