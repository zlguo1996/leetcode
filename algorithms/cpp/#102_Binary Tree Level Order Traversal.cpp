class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<TreeNode*> level;
        level.push_back(root);
        
        while (level.size()!=0) {
            int s = (int)level.size();
            vector<int> l;
            for (int i=0; i<s; i++) {
                l.push_back(level[i]->val);
                if(level[i]->left) level.push_back(level[i]->left);
                if(level[i]->right) level.push_back(level[i]->right);
            }
            
            res.push_back(l);
            level.erase(level.begin(), level.begin()+s);
        }
        
        return res;
    }
};102. Binary Tree Level Order Traversal
