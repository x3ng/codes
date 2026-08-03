function maxProfit(prices: number[]): number {
  let mv = prices[0];
  let mp = 0;
  for (const p of prices) {
    mv = Math.min(mv, p);
    mp = Math.max(mp, p - mv);
  }
  return mp;
}
