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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* currentPtr = head;
        ListNode* nextPtr = head->next;
        ListNode* prePtr = NULL;
        //find the last node and insert to the right place
        ListNode* ptr = currentPtr;
        while(currentPtr!= NULL && currentPtr->next != NULL) {
            nextPtr = currentPtr->next;
            while(ptr-next != NULL) {
                prePtr = ptr;
                ptr = ptr->next;
            }
            currentPtr->next = ptr;
            ptr->next = nextPtr;
            prePtr->next = NULL;
            currentPtr = nextPtr;
        }
        return head;
    }
};