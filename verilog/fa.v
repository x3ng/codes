module fa (
    i1,
    i2,
    i3,
    s,
    c
);

  input i1, i2, i3;
  output s, c;

  reg s, c;

  always @(i1 or i2 or i3) begin
    s = i1 ^ i2 ^ i3;
    c = (i1 * i2) | (i3 & (i1 ^ i2));
  end

endmodule
