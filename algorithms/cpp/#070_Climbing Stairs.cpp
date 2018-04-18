class Solution {
public:
    int climbStairs(int n) {
        int n0 = 1, n1 = 1;
        for(int i=2; i<=n; i++){
            int n2 = n0+n1;
            n0 = n1;
            n1 = n2;
        }
        return n1;
    }
};
