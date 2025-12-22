// first find the nodes in tree
// once found return from that
// branch
// check for left and right branches
// if both are not null then result 
// if the root;
// time : O(n), space : O(n)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (!root) return root;
       if (root == p || root == q) return root;
       TreeNode* left = lowestCommonAncestor(root->left, p, q);
       TreeNode* right = lowestCommonAncestor(root->right, p, q);
       if (!left) return right;
       if (!right) return left;
       return root;
    }
};
