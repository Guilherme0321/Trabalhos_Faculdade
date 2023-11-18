`include "clock.v"
`include "jkff.v"
module main;
    wire jqk01, jqk02, jqk03, jqk04, jqk05, jqk06, CLK;
    wire notjqk01, notjqk02, notjqk03, notjqk04, notjqk05, notjqk06;
    reg j, clear, preset;
    clock clk(.clk(CLK));
    jkff jqk_(.q(jqk01), .qnot(notjqk01), .j(jqk02), .k(~jqk02), .clk(CLK), .preset(1'b1), .clear(clear));
    jkff jqk_0(.q(jqk02), .qnot(notjqk02), .j(jqk03), .k(~jqk03), .clk(CLK), .preset(preset), .clear(clear));
    jkff jqk_1(.q(jqk03), .qnot(notjqk03), .j(jqk04), .k(~jqk04), .clk(CLK), .preset(preset), .clear(clear));
    jkff jqk_2(.q(jqk04), .qnot(notjqk04), .j(jqk05), .k(~jqk05), .clk(CLK), .preset(preset), .clear(clear));
    jkff jqk_3(.q(jqk05), .qnot(notjqk05), .j(jqk06), .k(~jqk06), .clk(CLK), .preset(preset), .clear(clear));
    jkff jqk_4(.q(jqk06), .qnot(notjqk06), .j(j), .k(~j), .clk(CLK), .preset(preset), .clear(clear));
    initial begin
        clear = 1'b1;
        #24 $display("%d %d %d - %d %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05, jqk06);
        clear = 1'b0;
        #24 $display("%d %d %d - %d %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05, jqk06);
        j = 1'b1;
        #24 $display("%d %d %d - %d %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05, jqk06);
        #24 $display("%d %d %d - %d %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05, jqk06);
        #24 $display("%d %d %d - %d %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05, jqk06);
        #24 $display("%d %d %d - %d %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05, jqk06);
        #24 $display("%d %d %d - %d %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05, jqk06);
        #24 $display("%d %d %d - %d %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05, jqk06);
        clear = 1'b0;
    end
endmodule