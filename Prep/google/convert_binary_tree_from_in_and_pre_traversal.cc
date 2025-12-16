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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        std::unordered_map<int, int> umap;
        for (int i = 0; i < inorder.size(); i++) umap[inorder[i]] = i;
        int pre_index = 0;
        return build_tree(preorder, 0, preorder.size() - 1, umap, pre_index);
    }

    TreeNode* build_tree(vector<int>& pre, int l, int r, std::unordered_map<int, int>& umap, int& pre_index) {
        if (l > r) return NULL;
        int root_val = pre[pre_index++];
        int ind = umap[root_val];
        TreeNode* root = new TreeNode(root_val);;
        root->left = build_tree(pre, l, ind - 1, umap, pre_index);
        root->right = build_tree(pre, ind + 1, r, umap, pre_index);
        return root;
    }
};
