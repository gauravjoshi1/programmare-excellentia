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
    vector<int> rightSideView(TreeNode* root) {
        //method 1 : level order traversal
        //method 2 : recursion with depth
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode* root, int curr_depth, vector<int>& res) {
        if (!root) return;
        if (curr_depth == res.size()) {
            res.push_back(root->val);
        }
        dfs(root->right, curr_depth + 1, res);
        dfs(root->left, curr_depth + 1, res);
    }
};
