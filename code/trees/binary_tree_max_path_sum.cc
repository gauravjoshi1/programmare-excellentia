// recursion : traverse left and right
// if !root return 0;
// keep a global max to keep track of
// max_sum seen till now
// once leaf node is recached get 
// max of max_sum and curr_val + left
// + right. return the max of l, r with
// curr_node added.
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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        dfs(root, max_sum);
        return max_sum;
    }

    int dfs(TreeNode* root, int& max_sum) {
        if (!root) return 0;
        int l = max(0, dfs(root->left, max_sum));
        int r = max(0, dfs(root->right, max_sum));
        max_sum = max(max_sum, root->val + l + r);
        return root->val + max(l, r); 
    }
};
