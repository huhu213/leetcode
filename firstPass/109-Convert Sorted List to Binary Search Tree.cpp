/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* next = cur->next;
        int i = 0;
        while(cur != NULL) {
            next = cur->next;
            i ++;
            pre = cur;
            cur = next;
        }
        int n = i;
        cur = head;
        pre = NULL;
        next = cur->next;
        for(i = 0; i < n/2; i ++) {
            pre = cur;
            cur = next;
            next = cur->next;
        }
        TreeNode* root = new TreeNode(cur->val);
        pre->next = NULL;
        cur->next = NULL;
        TreeNode* left = sortedListToBST(head);
        TreeNode* right = sortedListToBST(next);
        root->left = left;
        root->right = right;
        return root;
    }
};