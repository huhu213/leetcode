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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL) return head;
        ListNode* ptr = head;
        int length = 0;
        ListNode* tail = NULL;
        while(ptr != NULL) {
            length ++;
            tail = ptr;
            ptr = ptr->next;
        }
        if(length == 1) return head;
        if(k % length == 0) return head;
        k = k % length;
        ptr = head;
        int count = 0;
        ListNode* newtail = NULL;
        while(ptr != NULL && count < length - k) {
            newtail = ptr;
            ptr = ptr->next;
            count ++;
        }
        cout << count;
        tail->next = head;
        head = ptr;
        newtail->next = NULL;
        return ptr;
    }
};