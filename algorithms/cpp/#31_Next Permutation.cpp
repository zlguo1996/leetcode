class Solution {
public:
    void swap(int id1, int id2, vector<int>& nums){
        int a = nums[id1];
        nums[id1] = nums[id2];
        nums[id2] = a;
    }
    
    void nextPermutation(vector<int>& nums) {
        int right = nums.size()-1;
        
        int left = right-1;
        while(left>=0 && nums[left]>=nums[left+1]) left--;
        
        if(left>=0){
            int replaceid;
            for(int i=left+1; i<=right; i++){
                if(nums[i]<=nums[left]) break;
                replaceid = i;
            }
            swap(left, replaceid, nums);
        }
        
        left++;
        while(left<right){
            swap(left, right, nums);
            left++;
            right--;
        }
    }
};
