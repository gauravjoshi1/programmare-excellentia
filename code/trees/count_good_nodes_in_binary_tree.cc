// keep track of previous and current
// node, based on the question condition
// increase the good count and traverse
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
    int goodNodes(TreeNode* root) {
        int good = 0;
        dfs(root, root, good);
        return good;
    }

    void dfs(TreeNode* prev, TreeNode* curr, int& good) {
        if (!curr) return;
        if (curr->val >= prev->val) {
            good++;
            dfs(curr, curr->left, good);
            dfs(curr, curr->right, good);
        } else {
            dfs(prev, curr->left, good);
            dfs(prev, curr->right, good);
        }
    }
};
