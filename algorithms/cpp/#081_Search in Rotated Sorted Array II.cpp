class Solution {
public:
    bool bSearch(vector<int>& nums, int target, int left, int right){
        if(left>right) return false;
        int mid = (left+right)/2;
        int mid_n = nums[mid];
        
        if(target>mid_n){
            if(target==nums[right]) return true;
            else if(target<nums[right]||mid_n>nums[right]) return bSearch(nums, target, mid+1, right-1);
            else if(mid_n<nums[right]) return bSearch(nums, target, left, mid-1);
            else if(nums[left]==nums[right]) return bSearch(nums, target, mid+1, right-1)||bSearch(nums, target, left+1, mid-1);
            else return bSearch(nums, target, left, mid-1);
        }else if(target<mid_n){
            if(target==nums[left]) return true;
            else if(target>nums[left]||mid_n<nums[left]) return bSearch(nums, target, left+1, mid-1);
            else if(mid>nums[left]) return bSearch(nums, target, mid+1, right);
            else if(nums[left]==nums[right]) return bSearch(nums, target, mid+1, right-1)||bSearch(nums, target, left+1, mid-1);
            else return bSearch(nums, target, mid+1, right);
        }else{
            return true;
        }
    }
    bool search(vector<int>& nums, int target) {
        return bSearch(nums, target, 0, nums.size()-1);
    }
};
