// recursion : following tail recursion
// as we need to keep removing leaf node
// with the same target, so lets say
// if the leaf node value matches the target
// we remove that node and noe parent is also
// the leaf node, so we need to remove the parent
// which will be handled recursively.
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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* prev = new TreeNode(-1, root, NULL);
        delete_nodes(root, prev, target);
        return prev->left;
    }

    void delete_nodes(TreeNode* root, TreeNode* prev, int target) {
        if (!root) return;
        delete_nodes(root->left, root, target);
        delete_nodes(root->right, root, target);
        if (!root->left && !root->right) {
            if (root->val == target) {
                if (prev->left == root) prev->left = NULL;
                else prev->right = NULL;
            }
        }
    }
};
