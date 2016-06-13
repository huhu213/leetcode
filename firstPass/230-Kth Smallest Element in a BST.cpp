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
    vector<int> generate(TreeNode* root, int k) {
        vector<int> result;
        if(root == NULL) return result;
        if(root->left == NULL && root->right == NULL) {
            result.push_back(root->val);
            return result;
        }
        vector<int> left = generate(root->left, k);
        vector<int> right = generate(root->right, k);
        for(int i = 0; i < left.size(); i ++) {
            result.push_back(left[i]);
            if(result.size() == k) return result;
        }
        result.push_back(root->val);
        if(result.size() == k) return result;
        for(int i = 0; i < right.size(); i ++) {
            result.push_back(right[i]);
            if(result.size() == k) return result;
        }
        return result;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes = generate(root, k);
        return nodes[k-1];
    }
};