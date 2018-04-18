class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum=nums[0], csum=nums[0];
        
        for(int i=1; i<nums.size(); i++){
            if(csum<0) csum = 0;
            csum += nums[i];
            
            if(msum<csum) msum = csum;
        }
        
        return msum;
    }
};
