function maximizeSquareArea(m: number, n: number, hFences: number[], vFences: number[]): number {
    const MOD = 1000000007;

    const processFences = (fences: number[], border: number): number[] => {
	const unique = Array.from(new Set([...fences, 1, border]));
	return  unique.sort((a, b) => a-b);
    }

    const h = processFences(hFences, m);
    const v = processFences(vFences, n);

    const diffMap = new Map<number, number>();
    let maxSide = 0;
    for (const hi of h) {
	for (const vi of v) {
	    const diff = hi - vi;
	    if (diffMap.has(diff)) {
		maxSide = Math.max(maxSide, hi-diffMap.get(diff));
	    } else {
		diffMap.set(diff, hi);
	    }
	}
    }

    if (maxSide === 0) {
	return -1;
    } else {
	const maxAreas = BigInt(maxSide) * BigInt(maxSide) % BigInt(MOD);
	return Number(maxAreas);
    }
};
