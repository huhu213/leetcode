class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    	if(head == NULL or head->next == NULL){
    		return head;
    	}
        ListNode* newhead = head;
        ListNode* cur = head;
        ListNode* prev = NULL;
        while(cur != NULL){
        	ListNode* pnext = cur->next;
        	if(pnext == NULL){
        		return newhead;
        	}
        	else
        	{
        		ListNode* ppnext = pnext->next;
	        	pnext->next = cur;
	        	cur->next = ppnext;
		        if (prev == NULL)
		        {
		        	newhead = pnext;
		        	prev = cur;
		        }
		        else
		        {
		        	prev->next = pnext;
		        	prev = cur;
		        }
		        cur = ppnext;
        	}       	
    	}
    	return newhead;
    }
};