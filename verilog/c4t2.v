module c4t2 (
    i1,
    i2,
    i3,
    i4,
    ci,
    co,
    s,
    c
);

  input i1, i2, i3, i4, ci;
  output co, s, c;

  wire co, s, c;
  wire u1s;

  c3t2 c32u1 (
      .i1(i1),
      .i2(i2),
      .i3(i3),
      .s(u1s),
      .c(co)
  );

  c3t2 c32u2 (
      .i1(u1s),
      .i2(i4),
      .i3(ci),
      .s(s),
      .c(c)
  );

endmodule  // c4t2
