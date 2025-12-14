int xor_n(int n) {
  if (n < 0) {
    return 0;
  }
  int arr[4] = {n ,1, n+1, 0};
  return arr[n%4];
}

int xorOperation(int n, int start) {
  int a, b;
  a = start / 2;
  b = start & n & 1;
  return (xor_n(a+n-1)^xor_n(a-1)) * 2 + b;
}
