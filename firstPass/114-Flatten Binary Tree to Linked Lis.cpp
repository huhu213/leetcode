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
    TreeNode* generate(TreeNode* root) {
        if(root == NULL) return NULL;
        if(root->left == NULL && root->right == NULL) return root;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if(left == NULL) {
            TreeNode* rightLastNode = generate(right);
            return rightLastNode;
        }
        else if(right == NULL) {
            TreeNode* leftLastNode = generate(left);
            root->left = NULL;
            root->right = left;
            return leftLastNode;
        }
        else {
            root->left = NULL;
            TreeNode* leftLastNode = generate(left);
            TreeNode* rightLastNode = generate(right);
            root->right = left;
            leftLastNode->right = right;
            return rightLastNode;
        }       
    }

    void flatten(TreeNode* root) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        generate(root);
    }
};