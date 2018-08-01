class Solution {
public:
    bool isNumber(string s) {
        bool haveE = false, avaE = false, haveNum = false, haveP=false, avaP=false;
        int i=0;
        while(i<s.size() && s[i]==' ') i++;
        for (; i<s.size(); i++) {
            if(s[i]=='e') {
                if(!haveE) {
                    if(i==0) return false;
                    if((s[i-1]<'0'||s[i-1]>'9')&&s[i-1]!='.') return false;
                    haveE = true;
                    if(haveP!=avaP) return false;
                    haveP = false;
                    avaP = false;
                }
                else return false;
            }
            else if (s[i]=='.'){
                if(haveE) return false;
                if(!haveP) {
                    haveP = true;
                    if(i>0 && s[i-1]>='0'&& s[i-1]<='9') avaP = true;
                }
                else return false;
            }
            else if (s[i]>='0'&&s[i]<='9') {
                if (haveE==true&&avaE==false) avaE = true;
                if (haveP==true&&avaP==false) avaP = true;
                haveNum = true;
                continue;
            }
            else if (s[i]=='+'||s[i]=='-'){
                if(i>0&&((s[i-1]>='0'&&s[i-1]<='9')||s[i-1]=='.')) return false;
            }
            else if (s[i]==' ') break;
            else return false;
        }
        for (; i<s.size(); i++) {
            if(s[i]==' ') continue;
            else return false;
        }
        
        if(haveE==avaE&&haveNum&&haveP==avaP) return true;
        else return false;
    }
};
