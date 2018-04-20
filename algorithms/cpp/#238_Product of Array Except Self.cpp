class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int mul = 1;
        for(auto i:nums) mul *= i;
        
        vector<int> prod_left;
        vector<int> prod_right;
        prod_left.push_back(nums.front());
        prod_right.push_back(nums.back());
        for(int i=1; i<nums.size(); i++) prod_left.insert(prod_left.end(),nums[i]*prod_left.back());
        for(int i=nums.size()-2; i>=0; i--) prod_right.insert(prod_right.begin(),nums[i]*prod_right.front());
        
        vector<int> prod;
        prod.push_back(prod_right[1]);
        for(int i=1; i<nums.size()-1; i++) prod.push_back(prod_left[i-1]*prod_right[i+1]);
        prod.push_back(prod_left[nums.size()-2]);
        
        return prod;
    }
};
