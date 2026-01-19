function maxSideLength(mat: number[][], threshold: number): number {
    const m = mat.length;
    const n = mat[0].length;
    let maxSide = 0;
    const prew: number[][] = Array.from({length: m+1}, () => new Array(n+1).fill(0));
    for (let i=0; i<m; i++) {
	for (let j=0; j<n; j++) {
	    prew[i+1][j+1] = prew[i][j+1] + prew[i+1][j] - prew[i][j] + mat[i][j];
	    if (i>=maxSide && j>=maxSide) {
		const cs = prew[i+1][j+1] - prew[i+1][j-maxSide] - prew[i-maxSide][j+1] + prew[i-maxSide][j-maxSide];
		if (cs <= threshold) {
		    maxSide++;
		}
	    }
	}
    }
    return maxSide;
};
