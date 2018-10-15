class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        flatten(root->left);
        flatten(root->right);
        
        if (!root->left) return;
        TreeNode* r=root->left;
        while (r->right) r = r->right;
        r->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};
