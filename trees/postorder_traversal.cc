// recrusion -> left, right, root
// to simulate the above 
// we keep pushing the root and
// traverse towards the right subtree
// then pop and move left
// reverse the array for postorder
// as we first traversed root, right 
// and them move to left
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        while (root || !st.empty()) {
            while (root) {
                res.push_back(root->val);
                st.push(root);
                root = root->right;
            }
            root = st.top();
            st.pop();
            root = root->left;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void dfs(TreeNode* root, vector<int>& res) {
        if (!root) return;
        dfs(root->left, res);
        dfs(root->right, res);
        res.push_back(root->val);
    }
};
