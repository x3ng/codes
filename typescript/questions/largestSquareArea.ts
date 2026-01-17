function largestSquareArea(bottomLeft: number[][], topRight: number[][]): number {
    let maxSide = 0;
    const n = topRight.length;
    for (let i=0; i<n; i++) {
	if (maxSide >= Math.min(topRight[i][0]-bottomLeft[i][0], topRight[i][1]-bottomLeft[i][1])) {
	    continue;
	}
	for (let j=i+1; j<n; j++) {
	    const x = Math.min(topRight[i][0], topRight[j][0]) - Math.max(bottomLeft[i][0], bottomLeft[j][0]);
	    const y = Math.min(topRight[i][1], topRight[j][1]) - Math.max(bottomLeft[i][1], bottomLeft[j][1]);
	    maxSide = Math.max(maxSide, Math.min(x, y));
	}
    }
    return maxSide * maxSide;
};
