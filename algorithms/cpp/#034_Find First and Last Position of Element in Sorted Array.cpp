class Solution {
public:
    int searchRangeL(vector<int>& nums, int target, int l, int r){
        if(l==r){
            if(target==nums[l]) return l;
            else return -1;
        }
        
        int m = (l+r)/2;
        if(target<=nums[m]) return searchRangeL(nums, target, l, m);
        else return searchRangeL(nums, target, m+1, r);
    }
    
    int searchRangeR(vector<int>& nums, int target, int l, int r){
        if(l==r){
            if(target==nums[l]) return l;
            else return -1;
        }
        
        int m = (l+r+1)/2;
        if(target<nums[m]) return searchRangeR(nums, target, l, m-1);
        else return searchRangeR(nums, target, m, r);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        
        if(nums.empty()){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        res.push_back(searchRangeL(nums, target, 0, nums.size()-1));
        res.push_back(searchRangeR(nums, target, 0, nums.size()-1));
        
        return res;
    }
};
