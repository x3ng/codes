function groupAnagrams(strs: string[]): string[][] {
  const mp: Map<string, string[]> = new Map();
  for (const s of strs) {
    const sv = s.split("").sort().join("");
    if (!mp.has(sv)) {
      mp.set(sv, []);
    }
    mp.get(sv)?.push(s);
  }
  return Array.from(mp.values());
}
