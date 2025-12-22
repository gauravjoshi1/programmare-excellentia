// recursion : diameter is width
// so sum up the left and right
// width for result
//
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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dia(root, res);
        return res;
    }

    int dia(TreeNode* root, int& res) {
        if (!root) return 0;
        int l = dia(root->left, res);
        int r = dia(root->right, res);
        res = max(res, l + r);
        return 1 + max(l, r);
    }
};
