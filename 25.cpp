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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL or k == 1) return head;
        ListNode* phead = head;
        ListNode* ptr = head;
        ListNode* prev = NULL;  
        while(ptr != NULL){
            std::vector<ListNode*> v;
            int i = 0;
            while (i < k && ptr != NULL)
            {
                v.push_back(ptr);
                ptr = ptr->next;
                i ++;
            } 
            if (i < k)
            {
                return phead;
            }
            else{
                for (int j = k-1; j > 0; --j)
                {
                    v[j]->next = v[j-1];
                }
                v[0]->next = ptr;
                if (prev == NULL)
                {
                    phead = v[k-1];
                    prev = v[0];
                }
                else{
                    prev->next = v[k-1];
                    prev = v[0];
                }
            }
        }
        return phead;
    }
};