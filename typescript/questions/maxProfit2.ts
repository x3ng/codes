function maxProfit(prices: number[]): number {
  let mp = 0;
  for (let p = 1; p < prices.length; ++p) {
    const cp = prices[p] - prices[p - 1];
    mp += cp > 0 ? cp : 0;
  }
  return mp;
}
