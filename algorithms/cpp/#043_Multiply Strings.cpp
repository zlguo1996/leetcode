class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        
        int carry = 0;
        for (int i=0; i<=num2.size()+num1.size()-2; i++) {
            for (int j=(((int)num1.size()-1)>=i?i:((int)num1.size()-1)); (j>=0)&&(i-j<num2.size()); j--) {
                char c1=num1[num1.size()-1-j], c2=num2[num2.size()-1-(i-j)];
                carry += (int)(c1-'0')*(int)(c2-'0');
            }
            res = (char)(carry%10+'0') + res;
            
            carry /= 10;
        }
        
        while (carry>0) {
            res = (char)(carry%10+'0') + res;
            carry /= 10;
        }
        
        while (res.size()>1) {
            if(res[0]=='0') res.erase(0, 1);
            else break;
        }
        
        return res;
    }
};
