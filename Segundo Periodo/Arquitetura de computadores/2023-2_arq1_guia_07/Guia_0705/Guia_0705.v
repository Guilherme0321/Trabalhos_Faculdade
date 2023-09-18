module f7 (
    input a,
    input b, 
    input s,
    input s1, 
    input s2,
    output result 
);

wire not_resulta;
wire not_resultb;
wire and_result;
wire nand_result;
wire or_result;
wire nor_result;
wire xor_result;
wire xnor_result;

wire AND_NOTa, AND_NOTb, AND_AND, AND_NAND, AND_OR, AND_NOR, AND_XOR, AND_XNOR;

not NOT(not_resulta, a);
not NOT1(not_resultb,b);
and AND(and_result,a,b);
nand NAND(nand_result,a,b);
or OR(or_result,a,b);
nor NOR(nor_result,a,b);
xor XOR(xor_result,a,b);
xnor XNOR(xnor_result,a,b);

and AND05(AND_NOTa,~s,~s1,~s2, not_resulta);
and AND08(AND_NOTb,~s,~s1, s2, not_resultb);
and AND06(AND_AND,~s, s1, ~s2, and_result);
and AND07(AND_NAND,~s, s1, s2, nand_result);
and AND01(AND_OR,s, ~s1, ~s2,or_result);
and AND02(AND_NOR,s,~s1,s2,nor_result);
and AND03(AND_XOR,s,s1,~s2,xor_result);
and AND04(AND_XNOR,s,s1,s2,xnor_result);

or OR01(result,AND_NOTa,AND_NOTb,AND_AND,AND_NAND,AND_OR,AND_NOR,AND_XOR,AND_XNOR);

endmodule

module main;
    reg a, b, s, s1, s2;
    wire result;
    f7 F7 (
        .a(a),
        .b(b),
        .s(s),.s1(s1),.s2(s2),
        .result(result)
    );
    reg [2:0] counter;
    reg [3:0] i = 0;

    initial begin
        $display("a b selected resultado");
        
        for (i = 0;i < 8 ;i++ ) begin    
            for (counter = 0;counter < 4;counter++ ) begin
                a = counter[1];
                b = counter[0];
                s = i[2];
                s1 = i[1];
                s2 = i[0];
                #1;
                $display("%b %b %b%b%b %d", a, b, s,s1,s2,result);
            end
            $display("\n");
        end
        
    
        $finish;
    end
endmodule
