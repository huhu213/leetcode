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
        ListNode* currentPtr = head->next;
        ListNode* prePtr = head;
        //find the last node and insert to the right place
        ListNode* ptr = currentPtr;
        while(ptr->next != NULL) {
            ptr = ptr->next;
        }
        
    }
};