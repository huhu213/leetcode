//逆序后半段链表，合并两段链表
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
        ListNode* ptr = head->next;
        ListNode* prePtr = head;
        head->next = NULL;
        while(ptr != NULL) {
            ListNode* nextPtr = ptr->next;
            ptr->next = prePtr;
            prePtr = ptr;
            ptr = nextPtr;
        }
        return prePtr;
    }

    ListNode* mergeList(ListNode* head1, ListNode* head2) {
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        ListNode* ptr1 = head1;
        ListNode* ptr2 = head2;
        ListNode* prePtr = NULL;
        while(ptr1 != NULL && ptr2 != NULL) {
            ListNode* next1 = ptr1->next;
            ListNode* next2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = NULL;
            if(prePtr == NULL) prePtr = ptr2;
            else {
                prePtr->next = ptr1;
                prePtr = ptr2;
            }
            ptr1 = next1;
            ptr2 = next2;
        }
        if(ptr1 == NULL) {
            prePtr->next = ptr2;
        }
        return head1;
    }

    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        //reverse the second part of the list
        ListNode* ptr = head;
        int i = 0;
        while(ptr != NULL) {
            ptr = ptr->next;
            i ++;
        }
        int j = 0;
        ptr = head;
        while(j < i/2) {
            ptr = ptr->next;
            j ++;
        }
        ListNode* ptr2 = ptr;
        ptr = head;
        ptr2 = reverseList(ptr2);
        head = mergeList(ptr, ptr2);
        return;
    }
};