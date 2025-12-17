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
    int post_index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        std::unordered_map<int, int> umap;
        for (int i = 0; i < inorder.size(); i++) umap[inorder[i]] = i;
        post_index = postorder.size() - 1;
        return build_tree(umap, postorder, 0, postorder.size() - 1);
    }

    TreeNode* build_tree(std::unordered_map<int, int>& umap, vector<int>& post, int l, int r) {
        if (l > r) return NULL;
        int root_val = post[post_index--];
        TreeNode* root = new TreeNode(root_val);
        root->right = build_tree(umap, post, umap[root_val] + 1, r);
        root->left = build_tree(umap, post, l, umap[root_val] - 1);
        return root;
    }
};
