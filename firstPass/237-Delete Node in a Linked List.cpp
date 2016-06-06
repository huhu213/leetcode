/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL) return;
        ListNode* next = node->next;
        ListNode* cur = node;
        ListNode* pre = NULL;
        while(next != NULL) {
            cur->val = next->val;
            pre = cur;
            cur = next;
            next = cur->next;
        }
        pre->next = NULL;
        delete cur;
    }
};