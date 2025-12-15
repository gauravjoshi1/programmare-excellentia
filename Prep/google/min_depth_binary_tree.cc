/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int res = INT_MAX;
        dfs(root, 1, res);
        return res;
    }

    void dfs(TreeNode* root, int d, int& res) {
        if (!root) return;
        if (!root->left && !root->right) {
            res = min(res, d);
            return;
        }
        dfs(root->left, d + 1, res);
        dfs(root->right, d + 1, res);
    }
};
