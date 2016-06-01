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
	std::vector<string> generate(TreeNode* root) {
		std::vector<string> result;
		if(root == NULL) {
			result.push_back("");
			return result;
		}
		if(root->left == NULL && root->right == NULL) {
		    stringstream ss;
		    ss << root->val;
		    string s;
		    ss >> s;
			result.push_back(s);
			return result;
		}
		std::vector<string> leftSum = generate(root->left);
		stringstream ss;
		ss << root->val;
		string s;
		ss >> s;
		for(int i = 0; i < leftSum.size(); i ++) {
		    if(leftSum[i] == "") continue;
			else result.push_back(s+leftSum[i]);
		}
		std::vector<string> rightSum = generate(root->right);
		for(int i = 0; i < rightSum.size(); i ++) {
		    if(rightSum[i] == "") continue;
			else result.push_back(s+rightSum[i]);
		}
		return result;
	}
	
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return root->val;
        int result = 0;
        std::vector<string> v = generate(root);
        for(int i = 0; i < v.size(); i ++) {
            cout << v[i] << endl;
        	stringstream ss;
        	ss << v[i];
        	int num;
        	ss >> num;
        	result += num;
        }
        return result;

    }
};