/**
 * @param {number[][]} squares
 * @return {number}
 */
var separateSquares = function(squares) {
    let totalArea = 0n;
    const events = [];

    for (const sq of squares) {
        const cy = sq[1], cl = sq[2];
        totalArea += BigInt(cl) * BigInt(cl);
        events.push([cy, cl]);
        events.push([cy+cl, -cl]);
    }

    events.sort((a, b) => a[0] - b[0]);

    let coverWidth = 0;
    let currArea = 0;
    let prevHeight = 0;
    for (const [cy, dl] of events) {
        const ch = cy - prevHeight;
        const ca = coverWidth * ch;
        if (2n * BigInt(Math.ceil(ca + currArea)) >= totalArea) {
            return prevHeight+(Number(totalArea)-2.0*currArea) / (2.0*coverWidth);
        }
        coverWidth += dl;
        currArea += ca;
        prevHeight = cy;
    }
};
