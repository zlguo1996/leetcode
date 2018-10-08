class Solution {
public:
    void inorder(TreeNode* root, vector<int>& vec){
        if(!root) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);
    }
    TreeNode* findInt(TreeNode* tree, int obj){
        if(!tree) return NULL;
        if(tree->val==obj) return tree;
        else{
            TreeNode* n = findInt(tree->left, obj);
            if(!n) n= findInt(tree->right, obj);
            return n;
        }
    }
    void swapNode(TreeNode* a, TreeNode* b){
        int tmp;
        tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
    void recoverTree(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        
        int low, high;
        int tmp=INT_MIN;
        bool flag=false;
        for(auto i:vec){
            if(i<tmp){
                if(!flag) {
                    high = tmp;
                    low = i;
                    flag = true;
                }
                else{
                    low = i;
                    break;
                }
            }
            tmp = i;
        }
        
        TreeNode *l=findInt(root, low), *h=findInt(root, high);
        swapNode(l, h);
    }
};
