/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head);
    }

    TreeNode* dfs(ListNode* head) {
        if (!head) return NULL;
        ListNode* mid = get_mid(head);
        TreeNode* root = new TreeNode(mid->val);
        if (head == mid) {
            return root;
        }
        root->left = dfs(head);
        root->right = dfs(mid->next);
        return root;
    }

    ListNode* get_mid(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* sp = head;
        ListNode* fp = head;
        while (fp && fp->next) {
            prev = sp;
            sp = sp->next;
            fp = fp->next->next;
        }
        if (prev) prev->next = NULL;
        return sp;
    }
};


// method 2
 TreeNode* sortedListToBST(ListNode* head) {
        vector<int> inorder;
        while (head) {
            inorder.push_back(head->val);
            head = head->next;
        }
        return build_tree(inorder, 0, inorder.size() - 1);
    }

    TreeNode* build_tree(vector<int>& inorder, int l, int r) {
        if (l > r) return NULL;
        int mid = l + (r - l) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = build_tree(inorder, l, mid - 1);
        root->right = build_tree(inorder, mid + 1, r);
        return root;
    }
