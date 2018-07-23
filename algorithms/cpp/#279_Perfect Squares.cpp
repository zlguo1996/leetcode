class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        
        int next_square = 1;
        dp[0] = 0;
        for (int i=1; i<=n; i++) {
            if(i==next_square*next_square) {
                dp[i] = 1;
                next_square++;
            }
            else{
                int min_num = i;
                for (int j=1; j<next_square; j++) {
                    int tmp = dp[j*j]+dp[i-j*j];
                    min_num = min_num>tmp?tmp:min_num;
                }
                dp[i] = min_num;
            }
        }
        
        return dp[n];
    }
};
