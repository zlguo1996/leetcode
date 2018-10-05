class Solution {
public:
    int numTrees(int n) {
        if(n==0) return 0;
        vector<int> dp;
        dp.push_back(1);
        for (int i=1; i<=n; i++) {
            int n=0;
            for (int j=0; j<=i-1; j++) {
                n += dp[j]*dp[i-1-j];
            }
            dp.push_back(n);
        }
        return dp[n];
    }
};
