class Solution {
public:
    int numDecodings(string s) {
        int res = 0;
        int ppNum = 0, pNum = 1;
        int flag = 0;
        
        for (int i=0; i<s.size(); i++) {
            int num = s[i]-'0';
            
            if(num==1||num==2) {
                if(i<s.size()-1 && s[i+1]-'0'==0) {
                    res = pNum;
                    
                    flag = num;
                    ppNum = pNum;
                    pNum = res;
                    continue;
                }
            }
            
            if(flag==1) {
                if(num==0) res = pNum;
                else res = ppNum + pNum;
            }
            else if(flag==2){
                if(num==0) res = pNum;
                else if(num<=6) res = ppNum+pNum;
                else res = pNum;
            }
            else {
                if(num==0) return 0;
                res = pNum;
            }
            
            flag = num;
            ppNum = pNum;
            pNum = res;
        }
        
        return res;
    }
};
