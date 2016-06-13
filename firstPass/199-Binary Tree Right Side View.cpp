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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        std::queue<TreeNode*> nodes;
        nodes.push(root);
        while(nodes.size() > 0) {
            TreeNode* cur = nodes.front();
            int l = nodes.size();
            result.push_back(cur->val);
            for(int i = 0; i < l; i ++) {
                TreeNode* ptr = nodes.front();
                if(ptr->right != NULL) nodes.push(ptr->right);
                if(ptr->left != NULL) nodes.push(ptr->left);
                nodes.pop();
            }
        }
        return result;
    }
};