struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* last = NULL;
        bool flag = false;
        var tempResult = 0;

        while(ptr1 != NULL && ptr2!= NULL){
          tempResult = ptr1->val+ptr2->val;
          if(flag){
            ptr1->val = tempResult+1;
            ptr2->val = tempResult+1;
            flag = tempResult>=9 ? true : false;
          }
          else{
            ptr1->val = tempResult;
            ptr2->val = tempResult;
            flag = tempResult>=10 ? true : false;
          }

          last = ptr1;
          ptr1 = ptr1->next;
          ptr2 = ptr2->next;
        }

        if (ptr1 == NULL && ptr2!= NULL)
        {
          while(ptr2 != NULL){
            if (flag)
            {
              ptr2->val += 1;
            }
            flag = ptr2->val>=10?true : false;
            last = ptr2;
            ptr2 = ptr2->next;
          }
          if (flag)
          {
            ListNode* tempPtr = new ListNode(1);
            last->next = tempPtr;
          }

          return l2;
        }
        else if (ptr2 == NULL && ptr1!= NULL)
        {
          while(ptr1 != NULL){
            if (flag)
            {
              ptr1->val += 1;
            }
            flag = ptr1->val>=10?true : false;
            last = ptr1;
            ptr1 = ptr1->next;
          }
          if (flag)
          {
            ListNode* tempPtr = new ListNode(1);
            last->next = tempPtr;
          }

          return l1;
        }
        else{
          if (flag)
          {
            ListNode* tempPtr = new ListNode(1);
            last->next = tempPtr;
          }

          return l1;
        }
    }
  };