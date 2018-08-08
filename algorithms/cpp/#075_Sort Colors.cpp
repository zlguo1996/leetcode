class Solution {
public:
    void switchNum(vector<int>& nums, int i1, int i2){
        int num = nums[i1];
        nums[i1] = nums[i2];
        nums[i2] = num;
    }
    void sortColors(vector<int>& nums) {
        int last_zero=0, first_two=nums.size()-1;
        
        for (int i=0; i<=first_two; i++) {
            if(nums[i]==0) {
                switchNum(nums, last_zero, i);
                last_zero++;
            }else if(nums[i]==2){
                switchNum(nums, i, first_two);
                first_two--;
                if(nums[i]!=1) i--;
            }
        }
    }
};
