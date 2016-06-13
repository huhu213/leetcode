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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == NULL) return result;
        if(root->left == NULL && root->right == NULL) {
            stringstream ss;
            ss << root->val;
            string s;
            ss >> s;
            result.push_back(s);
            return result;
        }
        vector<string> left = binaryTreePaths(root->left);
        vector<string> right = binaryTreePaths(root->right);
        for(int i = 0; i < left.size(); i ++) {
            stringstream ss;
            ss << root->val;
            string s;
            ss >> s;
            s += "->";
            s += left[i];
            result.push_back(s);
        }
        for(int i = 0; i < right.size(); i ++) {
            stringstream ss;
            ss << root->val;
            string s;
            ss >> s;
            s += "->";
            s += right[i];
            result.push_back(s);
        }
        return result;
    }
};