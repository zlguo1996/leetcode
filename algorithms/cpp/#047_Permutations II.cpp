class Solution {
public:
    vector<vector<int>> my_permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()==0) res.push_back(nums);
        for (int i=0; i<nums.size(); i++) {
            int num = nums[i];
            if(i>=1&&nums[i-1]==num) continue;
            nums.erase(nums.begin()+i);
            vector<vector<int>> back = my_permuteUnique(nums);
            for (int j=0; j<back.size(); j++) {
                back[j].push_back(num);
                res.push_back(back[j]);
            }
            nums.insert(nums.begin()+i, num);
        }
        return res;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return my_permuteUnique(nums);
    }
};
