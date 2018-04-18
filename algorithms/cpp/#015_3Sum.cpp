class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<3) return result;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++){
            if(!result.empty()&&nums[i]==result.back()[0]) continue;
            
            int j=i+1, k=nums.size()-1;
            while(j<k){
                if(!result.empty()&&nums[i]==result.back()[0]&&nums[j]==result.back()[1]){
                    j++;
                    continue;
                }
                
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    int set[3] = {nums[i], nums[j], nums[k]};
                    result.push_back(vector<int>(set, set+3));
                    j++;
                    k--;
                }else if(sum<0){
                    j++;
                }else{
                    k--;
                }
            }
        }
        
        return result;
    }
};
