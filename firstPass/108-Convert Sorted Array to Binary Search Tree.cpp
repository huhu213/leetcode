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
    TreeNode* generate(std::vector<int>& nums, int s, int e) {
        if(s > e) return NULL;
        if(s == e) {
            TreeNode* root = new TreeNode(nums[s]);
            return root;
        }
        int rootLoc = (e + s + 1) / 2;
        TreeNode* left = generate(nums, s, rootLoc-1);
        TreeNode* right = generate(nums, rootLoc+1, e);
        TreeNode* root = new TreeNode(nums[rootLoc]);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) { 
        if(nums.size() == 0) return NULL;
        if(nums.size() == 1) {
            TreeNode* root = new TreeNode(nums[0]);
            return root;
        }
        return generate(nums, 0, nums.size()-1);
    }
};