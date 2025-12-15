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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return has_path_sum(root, targetSum, 0);
    }

    bool has_path_sum(TreeNode* root, int target, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return (sum + root->val) == target;
        return has_path_sum(root->left, target, sum + root->val) || has_path_sum(root->right, target, sum + root->val);
    }
};
