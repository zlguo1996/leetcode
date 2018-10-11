class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int bp, int bi, int l){
        if(l==0) return NULL;
        TreeNode* res = new TreeNode(preorder[bp]);
        
        int ll = 0;
        while (inorder[bi+ll]!=res->val) ll++;
        res->left = buildTree(preorder, inorder, bp+1, bi, ll);
        res->right = buildTree(preorder, inorder, bp+1+ll, bi+1+ll, l-ll-1);
        
        return res;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, 0, (int)preorder.size());
    }
};
