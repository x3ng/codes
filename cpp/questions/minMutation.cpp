class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int gs = startGene.size();
        int bs = bank.size();
        std::vector<std::vector<int>> edges(bs);
        int endp = -1;
        for (int sp=0; sp<bs; sp++) {
            if (endGene == bank[sp]) {
                endp = sp;
            }
            for (int dp=sp+1; dp<bs; dp++) {
                int mute = 0;
                for (int gb=0; gb<gs&&mute <= 1; gb++) {
                    mute += bank[sp][gb] != bank[dp][gb];
                }
                if (mute == 1) {
                    edges[sp].emplace_back(dp);
                    edges[dp].emplace_back(sp);
                }
            }
        }
        if (endp == -1) {
            return -1;
        }
        std::vector<bool> vis(bs, false);
        std::deque<int> tmp;
        for (int dp=0; dp<bs; dp++) {
            int mute = 0;
            for (int gb=0; gb<gs&&mute<=1; gb++) {
                mute += startGene[gb] != bank[dp][gb];
            }
            if (mute == 1) {
                tmp.push_back(dp);
                vis[dp] = true;
            }
        }
        for (int m=1; m<=bs&&tmp.size(); m++) {
            int cl = tmp.size();
            while (cl--) {
                int cc = tmp.front();
                if (cc == endp) {
                    return m;
                }
                tmp.pop_front();
                for (const auto& d: edges[cc]) {
                    if (!vis[d]) {
                        tmp.push_back(d);
                    }
                }
            }
        }
        return -1;
    }
};
