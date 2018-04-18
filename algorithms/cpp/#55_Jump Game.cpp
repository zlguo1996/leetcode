class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(i>max_index) return false;
            if(max_index>=nums.size()) return true;
            max_index = max(max_index, nums[i]+i);
        }
        return true;
    }
};
