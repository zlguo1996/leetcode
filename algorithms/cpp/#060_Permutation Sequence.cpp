class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        
        int n_factorial=1;
        int n_tmp = n-1;
        while (n_tmp>0) n_factorial *= n_tmp--;
        
        vector<int> nums(n, 0);
        for(int i=1; i<=n; i++) nums[i-1] = i;
        k--;
        while (n!=1) {
            int idx = k/n_factorial;
            int num = nums[idx];
            res += '0'+num;
            nums.erase(nums.begin()+idx);
            k = k%n_factorial;
            n_factorial /= --n;
        }
        res += '0' + nums[0];
        
        return res;
    }
};
