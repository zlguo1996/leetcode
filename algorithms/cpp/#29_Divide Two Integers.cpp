class Solution {
public:
    long divideL(long dividend, long divisor){
        if (dividend<0&&divisor<0) return divideL(-dividend, -divisor);
        else if(dividend>0&&divisor<0) return -divideL(dividend, -divisor);
        else if(dividend<0&&divisor>0) return -divideL(-dividend, divisor);
        
        long ans=0;
        int i = 31;
        while((divisor<<i>>1)!=(divisor<<(i-1))){
            i--;
        }
        while (dividend>=divisor) {
            if(dividend-(divisor<<i)>=0) {
                dividend -= divisor<<i;
                ans += (long)1<<i;
            }
            i--;
        }
        return ans;
    }

    int divide(int dividend, int divisor) {
        long ans = divideL(dividend, divisor);
        return ans>INT_MAX?INT_MAX:ans;
    }
};
