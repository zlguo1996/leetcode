class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
    
        int y = x;
    
        int digit_num=0;
        while(y/10!=0) {
            y /= 10;
            digit_num++;
        }
        digit_num++;
        int divide_num = (int)pow(10, digit_num-1);
    
        while(x>0){
            if(x%10!=x/divide_num) return false;
            x = (x%divide_num)/10;
            divide_num /= 100;
        }
        return true;
    }
};
