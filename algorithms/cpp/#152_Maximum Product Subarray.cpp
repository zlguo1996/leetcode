class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0], c=1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0) {
                c=1;
                ans = max(ans, 0);
            }
            else {
                c *= nums[i];
                ans = max(ans, c);
            }
        }
        c=1;
        for(int i=nums.size()-1; i>=0; i--){
            if(nums[i]==0) {
                c=1;
                ans = max(ans, 0);
            }
            else {
                c *= nums[i];
                ans = max(ans, c);
            }
        }
        
        return ans;
    }
};
