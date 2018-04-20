class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum1 = 0, sum2 = 0;
        for(auto i:nums) sum1 += i;
        for(int i=0; i<=nums.size(); i++) sum2 += i;
        return sum2-sum1;
    }
};
