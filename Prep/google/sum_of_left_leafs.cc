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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        sum(root, res, 'q');
        return res;
    }

    void sum(TreeNode* root, int& res, char dir) {
        if (!root) return;
        if (!root->left && !root->right && dir == 'l') {
            res += root->val;
            return;
        }
        sum(root->left, res, 'l');
        sum(root->right, res, 'r');
    }
};
