/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct PairNode
{
    TreeNode* node;
    bool visited;
    PairNode() : node(NULL), visited(false) {}
};

class Solution {
public:

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        if(root->left == NULL && root->right == NULL) {
            result.push_back(root->val);
            return result;
        }
        std::list<PairNode*> allNodes;
        PairNode* pn = new PairNode();
        pn->node = root;
        allNodes.push_back(pn);
        std::list<PairNode*>::iterator it = allNodes.begin();
        while(it != allNodes.end()) {
            cout << (*it)->node->val << endl;
            if((*it)->visited == true) it ++;
            else {
                TreeNode* ptr = (*it)->node;
                if(ptr->left == NULL && ptr->right == NULL) {
                    (*it)->visited = true;
                }
                else {
                    std::list<PairNode*>::iterator cur = it;
                    if(ptr->right != NULL) {
                        PairNode* tmp = new PairNode();
                        tmp->node = ptr->right;
                        allNodes.insert(cur, tmp);
                        cur --;
                    }
                    if(ptr->left != NULL) {
                        PairNode* tmp = new PairNode();
                        tmp->node = ptr->left;
                        allNodes.insert(cur, tmp);
                        cur --;
                    }
                    cout << allNodes.size() << endl;
                    (*it)->visited = true;
                    it = cur;
                }
            }
        }
        int i = 0;
        for(it = allNodes.begin(); it != allNodes.end(); ++ it) {
            result.push_back((*it)->node->val);
            cout << result[i] << " ";
            i ++;
        }
        return result;
    }
};