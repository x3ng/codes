#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int lr = 0;
        int ud = 0;
        for (const auto& c: moves) {
            switch (c) {
                case 'L':
                    --lr;
                    break;
                case 'R':
                    ++lr;
                    break;
                case 'U':
                    --ud;
                    break;
                case 'D':
                    ++ud;
                    break;
            }
        }
        return lr==0 && ud==0;
    }
};
