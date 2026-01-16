/**
 * @param {number} m
 * @param {number} n
 * @param {number[]} hFences
 * @param {number[]} vFences
 * @return {number}
 */
var maximizeSquareArea = function(m, n, hFences, vFences) {
    const MOD = 1000000007;
    const getEdges = (fences, border) => {
	const arr = [...new Set([...fences, 1, border])].sort((a, b) => b-a);
	const edges = [];
	for (let i=0; i<arr.length; i++) {
	    for (let j=i+1; j<arr.length; j++) {
		edges.push(arr[i]-arr[j]);
	    }
	}
	return [...new Set(edges)].sort((a, b) => b-a)
    }

    const hEdges = getEdges(hFences, m);
    const vEdges = getEdges(vFences, n);
    let i=0, j=0;
    while (i<hEdges.length && j<vEdges.length) {
	const hv = hEdges[i];
	const vv = vEdges[j];
	if (hv === vv) {
	    return Number(BigInt(hv)*BigInt(vv)%BigInt(MOD));
	} else if (hv > vv) {
	    i++;
	} else {
	    j++;
	}
    }
    return -1;
};
