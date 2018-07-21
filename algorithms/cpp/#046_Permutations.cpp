class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums){
		vector<vector<int>> res;
		if (nums.size() == 1) {
			vector<int > tmp;
			tmp.push_back(nums[0]);
			res.push_back(tmp);
			return res;
		}

		for (int i = 0; i<nums.size(); i++) {
			int front = nums[i];
			nums.erase(nums.begin() + i);
			vector<vector<int>> back = permute(nums);
			nums.insert(nums.begin() + i, front);
			for (int j = 0; j < back.size(); j++)
			{
				back[j].push_back(front);
				res.push_back(back[j]);
			}
		}

		return res;
	}
};
