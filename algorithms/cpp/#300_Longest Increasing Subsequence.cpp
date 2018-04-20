class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> lis;
        lis.push_back(1);
        for(int i=1; i<nums.size(); i++){
            int maxlis = 1;
            for(int j=0; j<i; j++){
                if(nums[i]>nums[j] && maxlis<lis[j]+1) maxlis = lis[j]+1;
            }
            lis.push_back(maxlis);
        }
        
        int ans = lis[0];
        for(int i=1; i<lis.size(); i++){
            if(lis[i]>ans) ans = lis[i];
        }
        
        return ans;
    }
};
