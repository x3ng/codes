#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    struct stat {
        int pos;
        int hea;
        int dir;
        int num;

        stat(int p, int h, int d, int n) : pos(p), hea(h), dir(d), num(n) {};
    };
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        std::vector<stat> rs;
        rs.reserve(n);
        for (int p=0; p<n; ++p) {
            rs.emplace_back(positions[p], healths[p], directions[p]=='R'?1:0, p);
        }
        std::sort(rs.begin(), rs.end(), [](stat a, stat b) -> bool {
                return a.pos < b.pos;
                });
        std::stack<stat> st;
        st.push(stat(-1, -1, -1, -1));
        for (auto& r: rs) {
            auto pt = st.top();
            if (r.dir==1 || pt.dir==0) {
                st.push(r);
            } else {
                while (pt.dir==1 && r.hea>pt.hea) {
                    r.hea -= 1;
                    st.pop();
                    pt = st.top();
                }
                if (pt.dir!=1) {
                    st.push(r);
                } else if (pt.hea > r.hea) {
                    st.top().hea -= 1;
                } else {
                    st.pop();
                }
            }
        }
        int as = st.size() - 1;
        vector<stat> tmp;
        tmp.reserve(as);
        while (st.size() > 1) {
            tmp.push_back(st.top());
            st.pop();
        }

        std::sort(tmp.begin(), tmp.end(), [](const stat& x, const stat& y) {
            return x.num < y.num;
        });

        vector<int> ans;
        ans.reserve(as);
        for (auto& s : tmp) {
            ans.push_back(s.hea);
        }

        return ans;
    }
};
