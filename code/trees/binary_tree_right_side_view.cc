// recursive : keep track of level
// if level is same as resultant
// arr size then push the current node
// in this first branching will be
// of right and then left, as we only
// need right side view.
//
//
// iterative follow level order traversal
// with the change of push right child first
// and then left
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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        dfs(root, res, 0);
        return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (i == 0) res.push_back(curr->val);
                if (curr->right) q.push(curr->right);
                if (curr->left) q.push(curr->left);
            }
        }
        return res;
    }

    void dfs(TreeNode* root, vector<int>& res, int lvl) {
        if (!root) return;
        if (lvl == res.size()) res.push_back(root->val);
        dfs(root->right, res, lvl + 1);
        dfs(root->left, res, lvl + 1);
    }
};
