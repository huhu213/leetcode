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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* next = cur->next;
        pre->next = NULL;
        while(cur != NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        if(head->next == NULL) return true;
        int n = 0;
        ListNode* ptr = head;
        while(ptr != NULL) {
            ptr = ptr->next;
            n ++;
        }
        ptr = head;
        if(n % 2 == 1) n = (n+1) / 2;
        else n = n / 2;
        int i = 0;
        while(i < n) {
            ptr = ptr->next;
            i ++;
        }
        ListNode* ptr1 = reverseList(ptr);
        ptr = head;
        while(ptr1 != NULL) {
            if(ptr->val == ptr1->val) {
                ptr1 = ptr1->next;
                ptr = ptr->next;
            }
            else return false;
        }
        return true;
    }
};