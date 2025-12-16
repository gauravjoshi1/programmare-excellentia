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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }

    void dfs(TreeNode* root, int& sum, int val) {
        if (!root) return;
        if (!root->left && !root->right) {
            sum += (val * 10) + root->val;
            return;
        }
        dfs(root->left, sum, (val * 10) + root->val);
        dfs(root->right, sum, (val * 10) + root->val);
    }
};
