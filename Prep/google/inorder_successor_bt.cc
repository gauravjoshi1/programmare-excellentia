TreeNode* get_left_most(TreeNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* inorder_successor(TreeNode* root, int target) {
    if (!root) return root;
    if (root->val == target && root->right) return get_left_most(root->right);

    TreeNode *succ = NULL;
    while (root) {
        if (target < root->val) {
            succ = root;
            root = root->left;
        } else if (target >= root->val) {
            root = root->right;
        }
    }
    return succ;
}
