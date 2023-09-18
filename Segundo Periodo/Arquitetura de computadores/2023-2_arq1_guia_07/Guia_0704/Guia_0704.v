module f7 (
    input a,
    input b, 
    input s,
    input s1, 
    output result 
);

wire or_result;
wire nor_result;
wire xor_result;
wire xnor_result;

wire AND_OR, AND_NOR, AND_XOR, AND_XNOR;

or OR(or_result,a,b);
nor NOR(nor_result,a,b);
xor XOR(xor_result,a,b);
xnor XNOR(xnor_result,a,b);

and AND01(AND_OR,~s,~s1,or_result);
and AND02(AND_NOR,~s,s1,nor_result);
and AND03(AND_XOR,s,~s1,xor_result);
and AND04(AND_XNOR,s,s1,xnor_result);

or OR01(result,AND_OR,AND_NOR,AND_XOR,AND_XNOR);

endmodule

module main;
    reg a, b, s, s1;
    wire result;
    f7 F7 (
        .a(a),
        .b(b),
        .s(s),.s1(s1),
        .result(result)
    );
    reg [2:0] counter, i = 0;

    initial begin
        $display("a b selected resultado");
        
        for (i = 0;i < 4 ;i++ ) begin    
            for (counter = 0;counter < 4;counter++ ) begin
                a = counter[1];
                b = counter[0];
                s = i[1];
                s1 = i[0];
                #1;
                $display("%b %b %b%b %d", a, b, s,s1,result);
            end
            $display("\n");
        end
        
    
        $finish;
    end
endmodule
