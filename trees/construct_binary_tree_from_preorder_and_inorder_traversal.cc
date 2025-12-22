// create a hash map which stores index
// for inorder array values, which
// will help in seperating left and
// right branches in tree.
// keep a global preorder index
// as in preorder we traverse
// root, left, right.
//
// time : O(n), space: O(n)


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
        int pre_index = 0;
        for (int i = 0; i < inorder.size(); i++) umap[inorder[i]] = i;
        return create_tree(preorder, 0, preorder.size() - 1, pre_index, umap);
    }

    TreeNode* create_tree(vector<int>& preorder, int l, int r, int& pre_index, std::unordered_map<int, int>& umap) {
        if (l > r) return NULL;
        int root_val = preorder[pre_index++];
        TreeNode* root = new TreeNode(root_val);
        root->left = create_tree(preorder, l, umap[root_val] - 1, pre_index, umap);
        root->right = create_tree(preorder, umap[root_val] + 1, r, pre_index, umap);
        return root;
    }
};
