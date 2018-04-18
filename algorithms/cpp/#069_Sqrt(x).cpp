class Solution {
public:
    double iterator(double& x, int r){
        x = (x+r/x)/2;
        return abs(r-x*x);
    }
    int mySqrt(int x) {
        if(x==0) return 0;
        double my_x = x;
        while(iterator(my_x, x)>0.1) ;
        return my_x;
    }
};
