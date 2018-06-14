class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int target){
        int mid_id = (left+right)/2;
        
        if(left>right) return -1;
        
        if(target>nums[mid_id]) {
            if(nums[mid_id]>nums[right]) left = mid_id+1;
            
            else if(target>nums[right]) right = mid_id-1;
            else if(target<nums[right]) left = mid_id+1;
            else return right;
        }
        else if(target<nums[mid_id]){
            if(nums[left]>nums[mid_id]) right = mid_id-1;
            
            else if(target>nums[left]) right = mid_id-1;
            else if(target<nums[left]) left = mid_id+1;
            else return left;
        }
        else return mid_id;
        
        return binarySearch(nums, left, right, target);
    }
    
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};
