class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<TreeNode*> level;
        level.push_back(root);
        
        bool flag = true;
        while (level.size()!=0) {
            int s = (int)level.size();
            vector<int> l;
            
            for (int i=0; i<s; i++) {
                if(flag) l.push_back(level[i]->val);
                else l.insert(l.begin(), level[i]->val);
                if(level[i]->left) level.push_back(level[i]->left);
                if(level[i]->right) level.push_back(level[i]->right);
            }
            
            res.push_back(l);
            level.erase(level.begin(), level.begin()+s);
            flag = !flag;
        }
        
        return res;
    }
};
