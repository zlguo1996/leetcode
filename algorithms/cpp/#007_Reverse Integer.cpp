class Solution {
public:
    int reverse(int x) {
        int flag;
        int digits[10];
        
        int isOverflow = 0;
        int overflowDig[10] = {
            2, 1, 4, 7, 4, 8, 3, 6, 4, 8
        };
        
        x>=0?flag=1:flag=-1;
        x *= flag;
        int i=0;
        while(x>0){
            digits[i] = x%10;
            if(isOverflow==0 && digits[i]>overflowDig[i]) isOverflow=1;
            if(isOverflow==0 && digits[i]<overflowDig[i]) isOverflow=-1;
            
            i++;
            x /= 10;
        }
        if(i<10) isOverflow=-1;
        if(isOverflow==0) isOverflow=1;
        
        if(isOverflow==1) return 0;
        else{
            int num=0;
            for(int m=0; m<i; m++){
                num = num*10+digits[m];
            }
            return num*flag;
        }
    }
};
