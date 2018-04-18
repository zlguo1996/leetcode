class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> solution;
        
        if(nums.size()<4) return solution;
        
        sort(nums.begin(), nums.end());
        
        for(int low1=0; low1<nums.size()-3; low1++){
            if(!solution.empty()&&nums[low1]==solution.back()[0]) continue;
            for(int low2=low1+1; low2<nums.size()-2; low2++){
                if(!solution.empty()&&nums[low1]==solution.back()[0]&&nums[low2]==solution.back()[1]) continue;
                
                int rSum = target-nums[low1]-nums[low2];
                int i=low2+1, j=nums.size()-1;
                while(i<j){
                    if(!solution.empty()&&nums[low1]==solution.back()[0]&&nums[low2]==solution.back()[1]&&nums[i]==solution.back()[2]){
                        i++;
                        continue;
                    } 
                    
                    if(nums[i]+nums[j]==rSum){
                        vector<int> r = {nums[low1], nums[low2], nums[i], nums[j]};
                        solution.push_back(r);
                    }else if(nums[i]+nums[j]<rSum){
                        i++;
                    }else{
                        j--;
                    }
                }
            }
        }
        
        return solution;
    }
};
