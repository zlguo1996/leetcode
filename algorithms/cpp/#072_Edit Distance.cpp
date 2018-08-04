class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word2.size()+1, vector<int>(word1.size()+1, 0));
        for(int i=0; i<word1.size()+1; i++) dp[0][i] = i;
        for(int i=0; i<word2.size()+1; i++) dp[i][0] = i;
        for (int i=1; i<word2.size()+1; i++) {
            for (int j=1; j<word1.size()+1; j++) {
                int m = min(dp[i][j-1]+1, dp[i-1][j]+1);
                if(word1[j-1]==word2[i-1]) dp[i][j] = min(dp[i-1][j-1], m);
                else dp[i][j] = min(dp[i-1][j-1]+1, m);
            }
        }
        
        return dp[word2.size()][word1.size()];
    }
};
