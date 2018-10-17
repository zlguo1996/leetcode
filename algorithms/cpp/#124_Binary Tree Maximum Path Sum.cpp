class Solution {
public:
	int maxPathSum(TreeNode* root, int& maxLeg) {
		if (!root) {
			maxLeg = 0;
			return INT_MIN;
		}
		int max_left_leg, max_right_leg;
		int res=INT_MIN;

		res = max(res, maxPathSum(root->left, max_left_leg));
		res = max(res, maxPathSum(root->right, max_right_leg));
		res = max(res, max(max_left_leg, 0) + max(max_right_leg, 0)+ root->val);

		maxLeg = max(max(max_right_leg, max_left_leg),0) + root->val;

		return res;
	}
	int maxPathSum(TreeNode* root) {
		int max_leg;
		return maxPathSum(root, max_leg);
	}
};
