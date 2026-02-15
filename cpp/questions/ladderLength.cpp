class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wss = wordList.size();
        int ws = beginWord.size();
        std::vector<std::vector<int>> edges(wss);
        std::vector<bool> vis(wss);
        int endp = -1;
        std::deque<int> steps;
        for (int i=0; i<wss; i++) {
            if (endWord == wordList[i]) {
                endp = i;
            }
            int df = 0;
            for (int p=0; p<ws && df <= 1; p++) {
                df += beginWord[p] != wordList[i][p];
            }
            if (df == 1) {
                steps.push_back(i);
                vis[i] = true;
            }
            for (int j=i+1; j<wss; j++) {
                df = 0;
                for (int p=0; p<ws && df <= 1; p++) {
                    df += wordList[i][p] != wordList[j][p];
                }
                if (df == 1) {
                    edges[i].emplace_back(j);
                    edges[j].emplace_back(i);
                }
            }
        }
        if (endp == -1) {
            return 0;
        }
        for (int step=2; steps.size()!=0; step++) {
            int cl = steps.size();
            while (cl--) {
                int cp = steps.front();
                if (cp == endp) {
                    return step;
                }
                steps.pop_front();
                for (const auto& np: edges[cp]) {
                    if (!vis[np]) {
                        steps.push_back(np);
                        vis[np] = true;
                    }
                }
            }
        }
        return 0;
    }
};
