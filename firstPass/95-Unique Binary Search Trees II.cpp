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
    vector<TreeNode*> generate(int s, int e) {
        std::vector<TreeNode*> result;
        if(s > e) return result;
        if(s == e) {
            TreeNode* root = new TreeNode(s);
            result.push_back(root);
            return result;
        }
        if(e-s == 1) {
            TreeNode* tree1 = new TreeNode(s);
            TreeNode* tree2 = new TreeNode(e);
            tree1->right = tree2;
            result.push_back(tree1);
            tree1 = new TreeNode(s);
            tree2 = new TreeNode(e);
            tree2->left = tree1;
            result.push_back(tree2);
            return result;
        }
        std::vector<TreeNode*> left = generate(s, e-1);
        std::vector<TreeNode*> right = generate(s+1, e);
        for(int i = 0; i < right.size(); i ++) {
            TreeNode* root = new TreeNode(s);
            root->right = right[i];
            result.push_back(root);
        }
        for(int i = s + 1; i < e; i ++) {
            std::vector<TreeNode*> left = generate(s, i-1);
            std::vector<TreeNode*> right = generate(i+1, e);
            for(int p = 0; p < left.size(); p ++) {
                for (int q = 0; q < right.size(); q ++)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[p];
                    root->right = right[q];
                    result.push_back(root);
                }
            }
        }
        for(int i = 0; i < left.size(); i ++) {
            TreeNode* root = new TreeNode(e);
            root->left = left[i];
            result.push_back(root);
        }
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        std::vector<TreeNode*> result;
        if(n == 1) {
            TreeNode* root = new TreeNode(1);
            result.push_back(root);
            return result;
        }
        return generate(1, n);
    }
};