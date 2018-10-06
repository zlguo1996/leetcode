Better to use [DP](https://leetcode.com/problems/interleaving-string/discuss/31879/My-DP-solution-in-C++)

class Solution {
public:
    bool countRep(string s1, int i1, string s2, int i2, string s3){
        int i3 = i1+i2;
        int i1t=i1, i2t=i2, i3t=i3;
        
        while (i1t<s1.size()&&s1[i1t]==s1[i1]) i1t++;
        while (i2t<s2.size()&&s2[i2t]==s2[i2]) i2t++;
        while (i3t<s3.size()&&s3[i3t]==s3[i3]) i3t++;
        
        int rep1=i1t-i1, rep2=i2t-i2, rep3=i3t-i3;
        if(rep3<min(rep1, rep2)||rep3>rep1+rep2) return false;
        else if (rep3<max(rep1, rep2)){
            if(rep1<rep2) return isInterleave(s1, i1+rep1, s2, i2+rep3-rep1, s3);
            else return isInterleave(s1, i1+rep3-rep2, s2, i2+rep2, s3);
        }else{
            return isInterleave(s1, i1+rep1, s2, i2+rep3-rep1, s3)|| isInterleave(s1, i1+rep3-rep2, s2, i2+rep2, s3);
        }
    }
    bool isInterleave(string s1, int i1, string s2, int i2, string s3){
        int i3 = i1+i2;
        if(i1==s1.size()&&i2==s2.size()) return true;
        else if(i1==s1.size()&&s2[i2]==s3[i3]) return isInterleave(s1, i1, s2, i2+1, s3);
        else if(i2==s2.size()&&s1[i1]==s3[i3]) return isInterleave(s1, i1+1, s2, i2, s3);
        
        if(s1[i1]==s3[i3]&&s2[i2]==s3[i3]){
            return countRep(s1, i1, s2, i2, s3);
        }else if (s1[i1]==s3[i3]){
            return isInterleave(s1, i1+1, s2, i2, s3);
        }else if (s2[i2]==s3[i3]){
            return isInterleave(s1, i1, s2, i2+1, s3);
        }else return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size()+s2.size()!=s3.size()) return false;
        vector<int> co(26, 0);
        for (auto c:s1) co[c-'a']++;
        for (auto c:s2) co[c-'a']++;
        for (auto c:s3) co[c-'a']--;
        for (auto c:co) if(c!=0) return false;
        return isInterleave(s1, 0, s2, 0, s3);
    }
};
