module lca (
    a,
    b,
    ci,
    s,
    co
);

  parameter WIDTH = 4;

  input [WIDTH-1:0] a, b;
  input ci;

  output [WIDTH-1:0] s;
  output co;

  wire [WIDTH-1:0] g, p;
  wire [WIDTH:0] c;

  assign c[0] = ci;
  assign g = a & b;
  assign p = a ^ b;

  genvar i;
  generate
    for (i = 0; i < WIDTH; i = i + 1) begin : gen_carry
      assign c[i+1] = g[i] | (p[i] & c[i]);
    end
  endgenerate

  assign s  = p ^ c[WIDTH-1:0];
  assign co = c[WIDTH];

endmodule  // lca

