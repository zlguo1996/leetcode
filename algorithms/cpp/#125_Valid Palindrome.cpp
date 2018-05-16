class Solution {
public:
    bool isCase(char c){
        if(c<='z'&&c>='a') return true;
        if(c<='Z'&&c>='A') return true;
        if(c<='9'&&c>='0') return true;
        return false;
    }
    bool isSame(char c1, char c2){
        if(c1<='9'&&c1>='0'){
            return c1==c2;
        }else{
            return c1==c2||c1==(c2+'A'-'a')||c2==(c1+'A'-'a');
        }
    }
    bool isPalindrome(string s) {
        int size = s.size();
        int i=0, j=size-1;
        while(i<j){
            if(!isCase(s[i])) {
                i++;
                continue;
            }
            if(!isCase(s[j])) {
                j--;
                continue;
            }
            if(!isSame(s[i], s[j])){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
