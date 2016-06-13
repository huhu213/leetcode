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
    int getDepth(TreeNode* root) {
        TreeNode* node = root;
        int dp = 0;
        while(node != NULL) {
            node = node->left;
            dp ++;
        }
        return dp;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        TreeNode* cur = root;
        int count  = 0;
        int lh = getDepth(root->left);
        int rh = getDepth(root->right);
        //左子树是满二叉树，层高为lh
        if(rh == lh) {
            count += pow(2, lh) - 1;
            count += 1;
            count += countNodes(root->right);
        }
        //右子树是满二叉树，层高为rh，比左子树矮一层
        else {
            count += pow(2, rh) - 1;
            count += 1;
            count += countNodes(root->left);
        }
        return count;
    }
};