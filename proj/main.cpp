#include "LeetcodeIO.hpp"

class Solution {
public:
	TreeNode* sortedListToBST(ListNode*& head,  int level, int max_level, int& max_level_count, int max_level_size) {
		if (level > max_level || max_level_count>max_level_size)  return NULL;
		TreeNode* tnp = new TreeNode(0);
		tnp->left = sortedListToBST(head, level + 1, max_level, max_level_count, max_level_size);
		tnp->val = head->val;
		head = head->next;
		if (level == max_level) max_level_count++;
		tnp->right = sortedListToBST(head, level + 1, max_level, max_level_count, max_level_size);
		return tnp;
	}
	TreeNode* sortedListToBST(ListNode* head) {
		int list_size = 0;
		while (head->next)
		{
			list_size++;
			head = head->next;
		}

		int max_level = 0;
		int exp = 1;
		while (exp<=list_size)
		{
			exp >> 1;
			max_level++;
		}
		int max_level_size = list_size+1 - exp << 1;

		int max_level_count = 0;
		return sortedListToBST(head, 1, max_level, max_level_count, max_level_size);
	}
};
	
int main() {
	cout << "hello world" << endl;
	getchar();
	return 0;
}