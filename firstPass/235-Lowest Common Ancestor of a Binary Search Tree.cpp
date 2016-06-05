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
    std::vector<TreeNode*> preorder(TreeNode* root) {
        std::vector<TreeNode*> result;
        if(root == NULL) return result;
        if(root->left == NULL && root->right == NULL) {
            result.push_back(root);
            return result;
        }
        std::vector<TreeNode*> left = preorder(root->left);
        std::vector<TreeNode*> right = preorder(root->right);
        result.push_back(root);
        for(int i = 0; i < left.size(); i ++) {
            result.push_back(left[i]);
        }
        for(int i = 0; i < right.size(); i ++) {
            result.push_back(right[i]);
        }
        return result;
    }

    std::std::vector<TreeNode*> inorder(TreeNode* root) {
        std::vector<TreeNode*> result;
        if(root == NULL) return result;
        if(root->left == NULL && root->right == NULL) {
            result.push_back(root);
            return result;
        }
        std::vector<TreeNode*> left = preorder(root->left);
        std::vector<TreeNode*> right = preorder(root->right);
        for(int i = 0; i < left.size(); i ++) {
            result.push_back(left[i]);
        }
        result.push_back(root);
        for(int i = 0; i < right.size(); i ++) {
            result.push_back(right[i]);
        }
        return result;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root) return p;
        if(q == root) return q;
        if(p == q->left || p == q->right) return p;
        if(q == p->left || q == p->right) return q;
        std::vector<TreeNode*> pre = preorder(root);
        std::vector<TreeNode*> in = inorder(root);
        
    }
};