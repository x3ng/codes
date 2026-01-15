function maximizeSquareHoleArea(n: number, m: number, hBars: number[], vBars: number[]): number {
    function getmc(sBars: number[]): number {
	let mc = 2, cc = 2;
	let prev = sBars[0];
	for (let p=1; p<sBars.length; p++) {
	    const curr = sBars[p];
	    if (curr === prev+1) {
		cc++;
	    } else {
		mc = Math.max(mc, cc);
		cc = 2;
	    }
	    prev = curr;
	}
	mc = Math.max(mc, cc);
	return mc;
    }
    hBars.sort((a, b) => a-b);
    vBars.sort((a, b) => a-b);
    const mmc = Math.min(getmc(hBars), getmc(vBars));
    return mmc * mmc;
};
