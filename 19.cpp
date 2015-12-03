class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
        {
            return head;
        }
        else
        {
            std::vector<ListNode*> v;
            ListNode* ptr = head;

            while(ptr != NULL)
            {
                v.push_back(ptr);
                ptr = ptr->next;
            }

            ListNode *newHead = v[0];
            if (n == v.size())
            {
                if(v.size() == 1)
                {
                    return NULL;
                }
                else
                {
                    return v[1];
                }
            }
            else
            {
                ListNode *prevPtr = v[v.size()-n-1];
                if(n == 1)
                {
                    prevPtr->next = NULL;
                }
                else
                {
                    ListNode *nextPtr = v[v.size()-n+1];
                    prevPtr->next = nextPtr;
                }
                
                return newHead;
            }
        }
        
    }
};