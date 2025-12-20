// recursion -> root, left, right
// iterative, simulating the recursion
// as we want root to be processed first then move to
// left and also store each right pointer if exists
// time : O(n) space : O(n)

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        while (root || !st.empty()) {
            while (root) {
                res.push_back(root->val);
                if (root->right) st.push(root->right);
                root = root->left;
            }
            if (!st.empty()) {
                root = st.top();
                st.pop();
            }
        }
        return res;
    }

    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        dfs(root->left, res);
        dfs(root->right, res);
    }
};
