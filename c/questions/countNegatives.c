int countNegatives(int** grid, int gridSize, int* gridColSize) {
    int ru = 0;
    int rd = gridSize-1;
    int cr = *gridColSize-1;
    int cl = cr;
    int ans = 0;
    while (ru<=rd && grid[ru][cr]>=0) {
        ru++;
    }
    while (ru<=rd && grid[ru][0]<0) {
        rd--;
        ans += *gridColSize;
    }
    while (ru <= rd) {
        while (cl>=0 && grid[ru][cl]<0) {
            cl--;
        }
        ans += cr-cl;
        ru++;
    }
    return ans;
}
