class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int dup = 0;
        for(int i=nums.size()-2;i>=0;i--){
            if (nums[i]==nums[i+1]) dup++;
            else{
                if(dup>1) nums.erase(nums.begin()+i+1, nums.begin()+i+dup);
                dup = 0;
            }
        }
        if(dup>1) nums.erase(nums.begin()+1, nums.begin()+dup);
        return nums.size();
    }
};
