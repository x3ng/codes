/**
 * @param {number[][]} points
 * @return {number}
 */
var minTimeToVisitAllPoints = function(points) {
    let ans = 0;
    for (let p=1; p<points.length; p++) {
        ans += Math.max(Math.abs(points[p][0]-points[p-1][0]), Math.abs(points[p][1]-points[p-1][1]));
    }
    return ans;
};
