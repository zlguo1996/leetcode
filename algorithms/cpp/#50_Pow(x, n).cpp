class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        if(n==-2147483648) return 1/myPow(x*x, 31);
        if(n<0) return 1/myPow(x, -n);
            
        while(n!=0){
            if(n%2==1) ans *= x;
            x *= x;
            n /= 2;
        }
        return ans;
    }
};
