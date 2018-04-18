class Solution {
public:
    int getDigit(char c){
        int i = (int)c-(int)'0';
        
        if(i>=0&&i<=9) return i;
        else return -1;
    }
    
    int myAtoi(string str) {
        int flag=1;
        bool isOf;
        
        int i=0;
        while(str[i]==' ') i++;
        
        if(str[i]=='-'){
            flag = -1;
            i++;
        }else if(str[i]=='+'){
            flag = 1;
            i++;
        }
        
        int num = getDigit(str[i]);
        i++;
        if(num==-1) return 0;
        while(getDigit(str[i])!=-1){
            int tnum = num*10+getDigit(str[i]);
            if(tnum/10!=num) return flag>0?INT_MAX:INT_MIN;
            num = tnum;
            i++;
        }
        return num*flag;
    }
};
