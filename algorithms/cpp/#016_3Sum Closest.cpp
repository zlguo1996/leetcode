class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result=1000000;
        if(nums.size()<3) return result;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++){
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<abs(result-target)){
                    result = sum;
                }
                
                if(sum>target){
                    k--;
                }else if(sum<target){
                    j++;
                }else{
                    k--;
                    j++;
                }
            }
        }
        
        return result;
    }
};
