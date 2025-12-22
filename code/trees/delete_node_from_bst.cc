// approach : find the node to be deleted
// keeping track of parent node
//
// check if it is a leaf node
// based on parent branch remove the node
// reference
//
// if the node doesn't have left child
// attach the right subtree of the node to
// be deleted to the parent
// 
// if node doesn't have right child
// attach the left subtree of the node to 
// be deleted to parent;
//
// if it has both left and right
// subtree find the inorder successor
// swap the value of the leaf, and current
// node and detach the leaf
//
// time : O(n), space O(1)


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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        TreeNode* curr = root;
        TreeNode* prev = new TreeNode(-1, root, NULL);
        TreeNode* res = prev;
        while (curr) {
            if (curr->val == key) break;
            prev = curr;
            if (curr->val > key) curr = curr->left;
            else curr = curr->right;
        }
        if (curr == NULL) return root;
        if (!curr->left && !curr->right) {
            if (prev->left == curr) prev->left = NULL;
            else prev->right = NULL;
        } else if (!curr->left) {
            if (prev->left == curr) prev->left = curr->right;
            else prev->right = curr->right;
        } else if (!curr->right) {
            if (prev->left == curr) prev->left = curr->left;
            else prev->right = curr->left;
        } else {
            TreeNode* succ = get_successor(curr);
            int t = curr->val;
            curr->val = succ->val;
            succ->val = t;
            prev = curr;
            curr = curr->right;
            while (curr->left) {
                prev = curr;
                curr = curr->left;
            }
            if (prev->left == curr) prev->left = curr->right;
            else prev->right = curr->right;
        }
        return res->left;;
    }

    TreeNode* get_successor(TreeNode* root) {
        root = root->right;
        while (root->left) root = root->left;
        return root;
    }
};

