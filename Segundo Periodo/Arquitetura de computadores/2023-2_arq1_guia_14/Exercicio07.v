`include "clock.v"
`include "jkff.v"
module test(
  output wire result,
  input j,
  input jqk06,
  input clock
);

  assign result = (j | jqk06);

endmodule

module main;
    wire jqk01, jqk02, jqk03, jqk04, jqk05, jqk06, CLK;
    wire notjqk01, notjqk02, notjqk03, notjqk04, notjqk05, notjqk06;
    reg j, clear, preset;
    wire result;

    
    clock clk(.clk(CLK));
    test teste(.result(result), .j(j), .jqk06(jqk05), .clock(CLK));
    jkff jqk_(.q(jqk01), .qnot(notjqk01), .j(result), .k(~result), .clk(CLK), .preset(preset), .clear(clear));
    jkff jqk_0(.q(jqk02), .qnot(notjqk02), .j(jqk01), .k(~jqk01), .clk(CLK), .preset(preset), .clear(clear));
    jkff jqk_1(.q(jqk03), .qnot(notjqk03), .j(jqk02), .k(~jqk02), .clk(CLK), .preset(preset), .clear(clear));
    jkff jqk_2(.q(jqk04), .qnot(notjqk04), .j(jqk03), .k(~jqk03), .clk(CLK), .preset(preset), .clear(clear));
    jkff jqk_3(.q(jqk05), .qnot(notjqk05), .j(jqk04), .k(~jqk04), .clk(CLK), .preset(preset), .clear(clear));
    initial begin
        preset = 1'b1;
        #24 $display("%d %d %d - %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05);
        preset = 1'b0;
        clear = 1'b1;
        #24 $display("%d %d %d - %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05);
        clear = 1'b0;
        j = 1'b1;
        #24 $display("%d %d %d - %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05);
        #24 $display("%d %d %d - %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05);
        j = 1'b0;
        #24 $display("%d %d %d - %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05);
        #24 $display("%d %d %d - %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05);
        #24 $display("%d %d %d - %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05);
        #24 $display("%d %d %d - %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05);
        #24 $display("%d %d %d - %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05);
        #24 $display("%d %d %d - %d %d\n", jqk01, jqk02, jqk03, jqk04, jqk05);
    end
endmodule