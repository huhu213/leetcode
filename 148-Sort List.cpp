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
    ListNode* merge(ListNode* ptr1, ListNode* ptr2) {
        if(ptr1 == NULL) return ptr2;
        if(ptr2 == NULL) return ptr1;
        ListNode* newhead = ptr1;
        //merge ptr2 to ptr1
        if(ptr1->val > ptr2->val) {
            newhead = ptr2;
            ptr2 = ptr2->next;
        }
        else ptr1 = ptr1->next;
        newhead->next = NULL;
        ListNode* currentPtr = newhead;
        while(ptr1 != NULL && ptr2 != NULL) {
            if(ptr2->val < ptr1->val) {
                currentPtr->next = ptr2;
                currentPtr = ptr2;
                currentPtr->next = NULL;
                ptr2 = ptr2->next;
            }
            else {
                currentPtr->next = ptr1;
                currentPtr = ptr1;
                currentPtr->next = NULL;
                ptr1 = ptr1->next;
            }
        }
        if(ptr1 == NULL) {
            currentPtr->next = ptr2;
        }
        else {
            currentPtr->next = ptr1;
        }
        return newhead;
    }


    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* ptr = head;
        int i = 0;
        while(ptr != NULL) {
            i ++;
            ptr = ptr->next;
        }
        int length = i;
        i = 0;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        ListNode* prePtr = NULL;
        while(i < length/2) {
            i ++;
            prePtr = ptr2;
            ptr2 = ptr2->next;
        }
        prePtr->next = NULL;
        prt1 = sortList(ptr1);
        ptr2 = sortList(ptr2);
        return merge(ptr1, ptr2);
    }
};