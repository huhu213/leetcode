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
    bool hasCycle(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next-Next == NULL) return head;
        ListNode* ptr = head;
        std:;unordered_set<ListNode*> nodeSet;
        while(ptr != NULL) {
        	if(nodeSet.find(ptr) == nodeSet.end()) continue;
        	else return true;
        }
        return false;
    }
};

