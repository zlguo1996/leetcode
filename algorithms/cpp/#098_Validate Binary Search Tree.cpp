// 使用inoder遍历输出到vector中，每次和上一个比较大小，速度可以加快一倍
// https://leetcode.com/problems/validate-binary-search-tree/discuss/177303/C++-((In-Order))-Easy-To-Understand-Solution-((Top-Best-Silicone-Valleys))

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
    bool isBetween(int i, int low, int high, bool lowf=false, bool highf=false){
        return (lowf||i>low) && (highf||i<high);
    }
    bool isValidBST(TreeNode* root, int low, int high, int lowf, int highf){
        if(!root) return true;
        if(!isBetween(root->val, low, high, lowf, highf)) return false;
        
        return isValidBST(root->left, low, root->val, lowf, false)&&isValidBST(root->right, root->val, high, false, highf);
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, INT_MIN, INT_MAX, true, true);
    }
};
