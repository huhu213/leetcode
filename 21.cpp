class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode* ptr1 = l1;
         ListNode* ptr2 = l2;
         if (ptr1 == NULL)
         {
             return ptr2;
         }
         else if (ptr2 == NULL)
         {
             return ptr1;
         }
         else
         {
             if (ptr1->val <= ptr2->val)
            {
                ListNode* cur = ptr1;
                ListNode* prev = NULL;
                while(cur != NULL && cur->val <= ptr2->val){
                    prev = cur;
                    cur = cur->next;
                }
                ListNode* temp = ptr2->next;
                prev->next = ptr2;
                ptr2->next = cur;
                cur = ptr2;
                ptr2 = temp;
                mergeTwoLists(cur, ptr2);
                return ptr1;
            }
            else
            {
                ListNode* temp = ptr1;
                ptr1 = ptr2;
                ptr2 = temp;
                return mergeTwoLists(ptr1, ptr2);
            }
         }
    }
};