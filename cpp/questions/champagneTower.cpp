class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        std::vector<double> rowc(query_row+1, 0);
        rowc[0] = static_cast<double>(poured);
        for (int r=0; r<query_row; r++) {
            double pre = 0;
            for (int p=0; p<=r+1; p++) {
                double cv = rowc[p]-1;
                cv = cv > 0 ? cv : 0;
                rowc[p] = pre/2 + cv/2;
                pre = cv;
            }
        }
        return rowc[query_glass] > 1 ? 1 : rowc[query_glass];
    }
};
