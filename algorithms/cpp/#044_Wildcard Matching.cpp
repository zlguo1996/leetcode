// 参考：https://www.cnblogs.com/Azhu/p/4397341.html

// 贪心算法
// 每次匹配最近两个‘*’之间的字符串，匹配成功即匹配下一对‘*’之间的字符串
class Solution {
public:
    bool singleMatch(char c1, char c2){
        return c1==c2||c1=='?'||c2=='?';
    }
    bool isMatch(string s, string p) {
        int i=0, j=0;
        int i_s = -1, j_s = -1;
        while (i<s.size()) {
            if(j==p.size()){
                if(j_s>=0){
                    i = ++i_s;
                    j = j_s+1;
                }else{
                    return false;
                }
            }
            if ((p[j]>='a'&&p[j]<='z')||p[j]=='?') {
                if(singleMatch(s[i], p[j])) {
                    i++;
                    j++;
                    continue;
                }
                else{
                    if(j_s>=0){
                        i = ++i_s;
                        j = j_s+1;
                    }else{
                        return false;
                    }
                }
            }
            else if (p[j]=='*'){
                i_s = i;
                j_s = j;
                j++;
            }
        }

        while (j<p.size()&&p[j]=='*') j++;
        if(j<p.size()) return false;
        else return true;
    }
};

// 动态规划
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        
        dp[0][0] = true;
        for (int i=1; i<=p.size(); i++) {
            if(p[i-1]=='*') dp[0][i] = dp[0][i-1];
        }
        
        for (int i=1; i<=s.size(); i++) {
            for (int j=1; j<=p.size(); j++) {
                if(p[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else dp[i][j] = (s[i-1]==p[j-1]||p[j-1]=='?')&&dp[i-1][j-1];
            }
        }
        
        return dp[s.size()][p.size()];
    }
};
