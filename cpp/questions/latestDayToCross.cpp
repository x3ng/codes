class UnionRegion {
private:    
    std::vector<int> regionMap;
public:
    UnionRegion(int n) : regionMap(n) {
        ranges::iota(regionMap, 0);
    }

    int rootSource(int n) {
        if (regionMap[n] != n) {
            regionMap[n] = rootSource(regionMap[n]);
        }
        return regionMap[n];
    }

    void mergeRegion(int s, int t) {
        int sr = rootSource(s);
        int tr = rootSource(t);
        regionMap[sr] = tr;
    }

    bool sameRegion(int a, int b) {
        return rootSource(a) == rootSource(b);
    }
};
    
class Solution {
private:
    static constexpr int DIRS[8][2] = {{0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}};
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int bl = row*col;
        int br = bl+1;
        UnionRegion urm(row*col+2);
        std::vector<std::vector<bool>> isWater(row+2, std::vector<bool>(col+2, false));
        for (int day=0; day<cells.size(); day++) {
            int r = cells[day][0];
            int c = cells[day][1];
            isWater[r][c] = true;
            int p = col*(r-1) + c-1;
            if (c == 1) {
                urm.mergeRegion(p, bl);
            }
            if (c == col) {
                urm.mergeRegion(p, br);
            }
            int rb;
            int cb;
            for (auto dir : DIRS) {
                rb = r + dir[0];
                cb = c + dir[1];
                if (isWater[rb][cb]) {
                    urm.mergeRegion(p, col*(rb-1)+cb-1);
                }
            }
            if (urm.sameRegion(bl, br)) {
                return day;
            }
        }
        return -1;
    }
};
