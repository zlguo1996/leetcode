class Solution {
public:
    int charToIndex(char c){
        return c>='a'?26+c-'a':c-'A';
    }
    string minWindow(string s, string t) {
        int slen = s.size(), tlen = t.size();
        
        int c_num[52] = {0};
        for (int i=0; i<t.size(); i++) c_num[charToIndex(t[i])]++;
        
        int left=0;
        int minLeft=-1, minLen=INT_MAX;
        for (int i=0; i<slen; i++) {
            if(c_num[charToIndex(s[i])]-->0) tlen--;
            
            while(left<slen && c_num[charToIndex(s[left])]<0) {
                c_num[charToIndex(s[left])]++;
                left++;
            }
            
            if(tlen==0 && minLen>i-left+1){
                minLeft = left;
                minLen = i-left+1;
            }
        }
        
        return minLeft==-1?"":s.substr(minLeft, minLen);
    }
};
