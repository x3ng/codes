#include <functional>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        std::function<TreeNode*(int, int)> bt = [&nums, &bt](int l, int r) -> TreeNode* {
            if (l > r) {
                return nullptr;
            }
            int m = (l + r) / 2;
            TreeNode* n = new TreeNode(nums[m]);
            n->left = bt(l, m-1);
            n->right = bt(m+1, r);
            return n;
        };
        return bt(0, nums.size()-1);
    }
};
