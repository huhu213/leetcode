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
    std::vector<TreeNode*> inorder(TreeNode* root) {
        std::vector<TreeNode*> result;
        if(root == NULL) return result;
        if(root->left == NULL && root->right == NULL) {
            result.push_back(root);
            return result;
        }
        std::vector<TreeNode*> left = inorder(root->left);
        std::vector<TreeNode*> right = inorder(root->right);
        for(int i = 0; i < left.size(); i ++) {
            result.push_back(left[i]);
        }
        result.push_back(root);
        for(int i = 0; i < right.size(); i ++) {
            result.push_back(right[i]);
        }
        return result;
    }

    int find(vector<TreeNode*> tree, TreeNode* p) {
        if(tree.size() == 0) return -1;
        for(int i = 0; i < tree.size(); i ++) {
            if(tree[i] == p) return i;
        }
        return -1;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == root) return p;
        if(q == root) return q;
        if(p == q->left || p == q->right) return q;
        if(q == p->left || q == p->right) return p;
        std::vector<TreeNode*> in = inorder(root);
        int leftSize = find(in, root);
        cout << find(in, p) << " " << find(in, root) << " " << find(in, q);
        if((find(in, p) < leftSize && find(in, q) > leftSize) || (find(in, p) > leftSize && find(in, q) < leftSize)) {
            return root;
        }
        else if(find(in, p) < leftSize && find(in, q) < leftSize) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};