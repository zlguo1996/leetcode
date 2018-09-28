class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ele;
        res.push_back(ele);
        
        sort(nums.begin(), nums.end());
        int beg=1;
        for (int i=0; i<nums.size(); i++) {
            int tmp = res.size();
            int cap = res.size();
            if(i>0&&nums[i-1]==nums[i]){
                for (int j=beg; j<cap; j++) {
                    res.push_back(res[j]);
                    res.back().push_back(nums[i]);
                }
                beg = tmp;
                continue;
            }
            for (int j=0; j<cap; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
            beg = tmp;
        }
        
        return res;
    }
};
