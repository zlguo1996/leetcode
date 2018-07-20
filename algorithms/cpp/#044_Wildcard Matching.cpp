class Solution {
public:
    bool singleMatch(char c1, char c2){
        return c1==c2||c1=='?'||c2=='?';
    }
    bool isMatch(string s, string p) {
        int i=0, j=0;
        int i_s = -1, j_s = -1;
        while (i<s.size()) {
            if(j==p.size()){
                if(j_s>=0){
                    i = ++i_s;
                    j = j_s+1;
                }else{
                    return false;
                }
            }
            if ((p[j]>='a'&&p[j]<='z')||p[j]=='?') {
                if(singleMatch(s[i], p[j])) {
                    i++;
                    j++;
                    continue;
                }
                else{
                    if(j_s>=0){
                        i = ++i_s;
                        j = j_s+1;
                    }else{
                        return false;
                    }
                }
            }
            else if (p[j]=='*'){
                i_s = i;
                j_s = j;
                j++;
            }
        }

        while (j<p.size()&&p[j]=='*') j++;
        if(j<p.size()) return false;
        else return true;
    }
};
