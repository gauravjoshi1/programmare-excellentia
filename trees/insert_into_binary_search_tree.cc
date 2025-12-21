// traverse the tree follwoing properties of
// bst keep track of the prev node once
// root becomes null attach the new node
// time : O(n), space : O(n);

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        insert(root, val, NULL);
        return root;
        TreeNode* temp = root;
        TreeNode* prev = NULL;
        while (root) {
            prev = root;
            if (root->val > val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        if (prev->val > val) {
            prev->left = new TreeNode(val);
        } else {
            prev->right = new TreeNode(val);
        }
        return temp;
    }

    void insert(TreeNode* root, int val, TreeNode* prev) {
        if (!root) {
            if (prev != NULL) {
                if (prev->val > val) prev->left = new TreeNode(val);
                else prev->right = new TreeNode(val);
            }
            return;
        }
        if (root->val > val) insert(root->left, val, root);
        if (root->val < val) insert(root->right, val, root);
    }
};
