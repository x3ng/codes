module ha (
    i1,
    i2,
    s,
    c
);
  input i1, i2;
  output s, c;

  assign s = i1 ^ i2;
  assign c = i1 & i2;

endmodule
