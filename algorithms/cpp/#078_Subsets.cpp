class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());
        
        for (int i=0; i<nums.size(); i++) {
            int tmp_size = res.size();
            for (int j=0; j<tmp_size; j++) {
                res.push_back(res[j]);
                (res.end()-1)->push_back(nums[i]);
            }
        }
        
        return res;
    }
};
