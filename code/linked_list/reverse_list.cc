// recursive approach is to reach the
// end node and make it point to the prev
// node, which is head below then
// detach the head
//
//
// iterative : traverse the list 
// one by one detach the head and point to
// prev node.
//
// time : O(n), space :O(n)/ O(1) for iterative

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
        // ListNode* temp = reverse(head);
        // head->next = NULL;
        // return temp;
        ListNode* prev = NULL;
        while (head) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    ListNode* reverse(ListNode* head) {
        if (!head) return NULL;
        ListNode* temp = reverse(head->next);
        if (!temp) return head;
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
};
