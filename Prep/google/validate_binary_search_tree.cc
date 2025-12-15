bool valid_binary_search_tree(TreeNode* root) {
    if (!root) return true;
    return is_valid(root, LLONG_MIN, LLONG_MAX);
}

bool is_valid(TreeNode* root, long long left, long long right) {
    if (!root) return true;
    if (root->val <= left || root->val >= right) return false;
    return is_valid(root->left, left, root->val) && is_valid(root->right, root->val, right);
}

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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *pre = NULL;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (pre != NULL && root->val <= pre->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};
