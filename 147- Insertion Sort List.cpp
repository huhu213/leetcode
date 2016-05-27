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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newhead = head;
        ListNode* lastPtr = head;
        ListNode* ptr = head->next;
        ListNode* prePtr = NULL;
        while(ptr != NULL && ptr->val >= lastPtr->val) {
            lastPtr = ptr;
            ptr = ptr->next;
        }
        if(ptr == NULL) return newhead;
        else if(lastPtr == head){
            prePtr = NULL;
        }
        else prePtr = lastPtr;
        lastPtr->next = NULL;
        while(ptr != NULL) {
        	//save next node
        	ListNode* next = ptr->next;
        	ptr->next = NULL;
        	//loc current node in the new list
        	ListNode* newptr = newhead;
        	prePtr = NULL;
        	while(newptr != NULL && newptr->val <= ptr->val) {
        		prePtr = newptr;
        		newptr = newptr->next;
        	}
        	if(prePtr == NULL) {
        		ptr->next = newptr;
        		newhead = ptr;
        	}
        	else {
        		prePtr->next = ptr;
        		ptr->next = newptr;
        	}
        	ptr = next;
        }
        return newhead;
    }
};