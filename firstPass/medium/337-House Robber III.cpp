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
    void getMaxMoney(TreeNode* root, int& moneyWithRoot, int &moneyWithoutRoot) {
        if(root == NULL) return;
        int moneyWithLeft = 0, moneyWithoutLeft = 0;
        getMaxMoney(root->left, moneyWithLeft, moneyWithoutLeft);
        int moneyWithRight = 0, moneyWithoutRight = 0;
        getMaxMoney(root->right, moneyWithRight, moneyWithoutRight);
        moneyWithRoot = max(moneyWithRoot, root->val + moneyWithoutLeft + moneyWithoutRight);
        int tmp = max(moneyWithLeft, moneyWithoutLeft) + max(moneyWithRight, moneyWithoutRight);
        moneyWithoutRoot = max(moneyWithoutRoot, tmp);
    }



    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == 0 && root->right == 0) return root->val;
        int moneyWithRoot = 0, moneyWithoutRoot = 0;
        getMaxMoney(root, moneyWithRoot, moneyWithoutRoot);
        return max(moneyWithRoot, moneyWithoutRoot);
    }
};