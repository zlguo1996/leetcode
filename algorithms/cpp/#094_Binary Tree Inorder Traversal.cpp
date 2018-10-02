class Solution {
public:
    void rec(TreeNode* root, vector<int>& res){
        if(root==NULL) return;
        rec(root->left, res);
        res.push_back(root->val);
        rec(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        rec(root, res);
        return res;
    }
};
