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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL || head->next->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = even;
        ListNode* ptr = even->next;
        odd->next = NULL;
        even->next = NULL;
        ListNode* pre = NULL;
        int i = 1;
        while(ptr != NULL) {
            if(i % 2 == 1) {
                odd->next = ptr;
                odd = ptr;
                pre = odd;
                ptr = ptr->next;
                odd->next = NULL;
            }
            else {
                even->next = ptr;
                even = ptr;
                ptr = ptr->next;
                even->next = NULL;
            }
            i ++;
        }
        pre->next = evenhead;
        return head;
    }
};