class Solution {
public:
    long mul(long maximum, long minimum){
        long ans=1;
        while(maximum>minimum){
            ans *= maximum;
            maximum--;
        }
        return ans;
    }
    int uniquePaths(int m, int n) {
        m--; n--;
        int mn = m+n;
        int maximum = max(m, n);
        int minimum = min(m, n);
        return mul(mn, maximum)/mul(minimum, 0);
    }
};