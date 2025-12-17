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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        vector<vector<int>> res;
        queue<pair<TreeNode*, pair<int, vector<int>>>> q;
        q.push({root, {root->val, {root->val}}});
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (is_leaf(curr.first)) {
                if (curr.second.first == targetSum) res.push_back(curr.second.second);
                continue;
            }
            if (curr.first->left) {
                vector<int> temp = curr.second.second;
                temp.push_back(curr.first->left->val);
                q.push({curr.first->left, {curr.second.first + curr.first->left->val, temp}});
            }
            if (curr.first->right) {
                vector<int> temp = curr.second.second;
                temp.push_back(curr.first->right->val);
                q.push({curr.first->right, {curr.second.first + curr.first->right->val, temp}});
            }
        }
        return res;
    }

    bool is_leaf(TreeNode* root) {
        return !root->left && !root->right;
    }
};


vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        dfs(root, targetSum, res, {});
        return res;
    }

    void dfs(TreeNode* root, int target, vector<vector<int>>& res, vector<int> temp) {
        if (!root) return;
        if (!root->left && !root->right) {
            if ((target - root->val) == 0) {
                temp.push_back(root->val);
                res.push_back(temp);
            }
            return;
        }
        temp.push_back(root->val);
        dfs(root->left, target - root->val, res, temp);
        dfs(root->right, target - root->val, res, temp);
    }
