class Solution {
public:
    int jump(vector<int>& nums) {
        int min_jumps=0;
    
    for(int i=0; i<nums.size()-1; ){
        int max_idx = i+nums[i];
        if(max_idx>=nums.size()-1) {
            min_jumps++;
            break;
        }
        int max_idx_2 = max_idx+nums[max_idx];
        int new_i = max_idx;
        for(int j=i+1; j<i+nums[i]; j++){
            if(j+nums[j]>max_idx_2) {
                new_i = j;
                max_idx_2 = j+nums[j];
            }
        }
        min_jumps++;
        i = new_i;
    }
    return min_jumps;
    }
};
