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
    vector<TreeNode*> generateTrees(int s, int e){
        vector<TreeNode*> res;
        if (s==e) {
            res.push_back(NULL);
            return res;
        }
        for(int i=s; i<e; i++){
            vector<TreeNode*> left = generateTrees(s, i);
            vector<TreeNode*> right = generateTrees(i+1, e);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* n = new TreeNode(i);
                    n->left = l;
                    n->right = r;
                    res.push_back(n);
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            vector<TreeNode*> n;
            return n;
        }
        return generateTrees(1, n+1);
    }
};
