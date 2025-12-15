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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int h_l = height(root->left);
        int h_r = height(root->right);
        if (abs(h_l - h_r) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode *root) {
        if (!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l, r);
    }
};
