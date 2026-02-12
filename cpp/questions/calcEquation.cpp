class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        std::unordered_map<string, int> enc;
        int en = equations.size();
        for (int p=0; p<en; p++) {
            if (enc.find(equations[p][0]) == enc.end()) {
                enc[equations[p][0]] = nvars++;
            }
            if (enc.find(equations[p][1]) == enc.end()) {
                enc[equations[p][1]] = nvars++;
            }
        }
        std::vector<std::vector<std::pair<int, double>>> edges(nvars);
        for (int p=0; p<en; p++) {
            int ef = enc[equations[p][0]];
            int es = enc[equations[p][1]];
            double vl = values[p];
            edges[ef].push_back({es, vl});
            edges[es].push_back({ef, 1.0 / vl});
        }
        std::vector<double> ans(queries.size(), -1.0);
        for (int p=0; p<queries.size(); p++) {
            if (enc.find(queries[p][0])!=enc.end() && enc.find(queries[p][1])!=enc.end()) {
                int qf = enc[queries[p][0]];
                int qs = enc[queries[p][1]];
                if (qf == qs) {
                    ans[p] = 1.0;
                } else {
                    std::queue<int> rg;
                    rg.push(qf);
                    std::vector<double> ret(nvars, -1.0);
                    ret[qf] = 1.0;
                    while (rg.size()) {
                        int ce = rg.front();
                        rg.pop();
                        for (const auto& [d, v]: edges[ce]) {
                            if (ret[d] < 0) {
                                ret[d] = ret[ce] * v;
                                rg.push(d);
                            }
                        }
                    }
                    ans[p] = ret[qs];
                }
            }
        }
        return ans;
    }
};
