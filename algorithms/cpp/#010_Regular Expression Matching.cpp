class Solution {
public:
    bool isMatchChar(char s, char p){
        if(p=='.'||s=='.') return true;
        else if(p==s) return true;
        else return false;
    }
    
    bool isMatch(string s, string p) {
        int j=0;
        
        for(int i=0; i<p.length(); i++){
            char c = p[i];
            if(i+1<p.length() && p[i+1]=='*'){
                if(isMatch(string(s, j), string(p, i+2))) return true;
                while(j<s.length() && isMatchChar(s[j], c)){
                    bool flag = isMatch(string(s, j+1), string(p, i+2));
                    j++;
                    if(flag) return true;
                }
                return isMatch(string(s, j), string(p, i+2));
            }else{
                if(j<s.length() && isMatchChar(s[j],c)) j++;
                else return false;
            }
        }
        
        if(j==s.length()) return true;
        else return false;
    }
};
