// recursion : get height for left and
// right branches and if height diff
// is greater than 1 return false ;
// time : O(nlogn), space : O(n)
//
//




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
        int l = height(root->left);
        int r = height(root->right);
        if (abs(l - r) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int height(TreeNode* root) {
        if (!root) return 0;
        int l = height(root->left);
        int r = height(root->right);
        return 1 + max(l, r);
    }
};
