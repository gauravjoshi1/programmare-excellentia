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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) return {};
        vector<string> res;
        dfs(root, "", res);
        return res;
    }

    void dfs(TreeNode* root, string temp, vector<string>& res) {
        if (!root) return;
        if (!root->left && !root->right) {
            temp += to_string(root->val);
            res.push_back(temp);
            return;
        }
        dfs(root->left, temp + to_string(root->val) + "->", res);
        dfs(root->right, temp + to_string(root->val) + "->", res);
    }
};
