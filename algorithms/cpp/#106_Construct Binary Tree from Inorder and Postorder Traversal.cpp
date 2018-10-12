class Solution {
public:
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder, int bp, int bi, int l){
        if(l==0) return NULL;
        TreeNode* res = new TreeNode(postorder[bp]);
        
        int ll = 0;
        while (inorder[bi-ll]!=res->val) ll++;
        res->right = buildTree(postorder, inorder, bp-1, bi, ll);
        res->left = buildTree(postorder, inorder, bp-1-ll, bi-1-ll, l-ll-1);
        
        return res;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(postorder, inorder, postorder.size()-1, postorder.size()-1, (int)postorder.size());
    }
};
