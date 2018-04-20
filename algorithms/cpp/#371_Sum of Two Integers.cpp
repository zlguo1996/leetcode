class Solution {
public:
    int getSum(int a, int b) {
        if(b==0) return a;
        else{
            int c = a ^ b;
            int d = (a & b) << 1;
            return getSum(c, d);
        }
    }
};
