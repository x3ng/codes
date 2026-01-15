/**
 * @param {number} n
 * @param {number} m
 * @param {number[]} hBars
 * @param {number[]} vBars
 * @return {number}
 */
var maximizeSquareHoleArea = function(n, m, hBars, vBars) {
    let getmc = function(Bars) {
	Bars.sort((a, b) => a-b);
	let mc = 2;
	let cc = 2;
	let prev = Bars[0];
	let curr;
	for (let p=1; p<Bars.length; p++) {
	    curr = Bars[p];
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
    const mmc = Math.min(getmc(hBars), getmc(vBars));
    return mmc * mmc;
};
