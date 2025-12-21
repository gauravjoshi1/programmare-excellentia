// approach : pass a min and max val with node
// check if curr node val is greater than min_val
// or less that max_val return false
// call for branches left and right ajust min
// and max value accordingly
// time : O(n), space : O(n)


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
    bool isValidBST(TreeNode* root) {
        return is_valid(root, LLONG_MIN, LLONG_MAX);
    }

    bool is_valid(TreeNode* root, long long min_val, long long max_val) {
        if (!root) return true;
        if (min_val >= root->val || max_val <= root->val) return false;
        return is_valid(root->left, min_val, root->val) && is_valid(root->right, root->val, max_val);
    }
};
