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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode* temp = _reverse(head);
        head->next = NULL;
        return temp;
    }

    ListNode* _reverse(ListNode* head) {
        if (!head) return head;
        ListNode* temp = _reverse(head->next);
        if (!temp) return head;
        head->next->next = head;
        return temp;
    }
};
