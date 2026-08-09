class RandomizedSet {
  private dt = new Map<number, number>();
  private v: number[] = [];

  constructor() {}

  insert(val: number): boolean {
    if (this.dt.has(val)) {
      return false;
    }
    this.dt.set(val, this.v.length);
    this.v.push(val);
    return true;
  }

  remove(val: number): boolean {
    const idx = this.dt.get(val);
    if (idx == undefined) {
      return false;
    }
    const ev = this.v[this.v.length - 1];
    this.dt.set(ev, idx);
    this.v[idx] = ev;
    this.v.pop();
    this.dt.delete(val);
    return true;
  }

  getRandom(): number {
    const idx = Math.floor(Math.random() * this.v.length);
    return this.v[idx];
  }
}
