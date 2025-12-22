// recursive : follow inorder traversal
// after reaching left most leaf decrement
// k, check if k is zero return the node val
//
// simulate the above using stack(inorder)
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
    int kthSmallest(TreeNode* root, int k) {
        //int val = 0;
        //dfs(root, k, val);
        //return val;

        stack<TreeNode*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            k--;
            if (k == 0) return root->val;
            root = root->right;
        }
        return -1;
    }
    
    void dfs(TreeNode* root, int& k, int& val) {
        if (!root) return;
        dfs(root->left, k, val);
        k--;
        if (k == 0) {
            val = root->val;
            return;
        }
        dfs(root->right, k, val);
    }
};
