// fast solution(use hash map) O(N*K) N:strs.size(), K:str.size()
class Solution {
public:
    void strSort(string& str){
        int dict[26] = {0};
        for(auto c:str){
            dict[c-'a']++;
        }
        str = "";
        for (int i=0; i<26; i++) {
            while (dict[i]>0) {
                str += (char)('a'+i);
                dict[i]--;
            }
        }
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        
        for(auto str:strs){
            string ctnt = str;
            strSort(str);
            mp[str].push_back(ctnt);
        }
        for(auto v:mp){
            res.push_back(v.second);
        }
        
        return res;
    }
};

// slow solution(no hash map) O(N^2*K) N:strs.size(), K:str.size()
class Solution {
public:
    vector<int> countChar(string str){
        vector<int> alpha(26, 0);
        for(auto c:str){
            alpha[c-'a']++;
        }
        return alpha;
    }
    bool matchChar(vector<int>& a1, vector<int>& a2){
        for (int i=0; i<26; i++) {
            if(a1[i]!=a2[i]) return false;
        }
        return true;
    }
    int findChar(vector<vector<int>>& dict, vector<int>& a){
        for (int i=0; i<dict.size(); i++) {
            if(matchChar(dict[i], a)) return i;
        }
        return -1;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<vector<int>> alphaCount;
        
        for(auto str:strs){
            vector<int> a = countChar(str);
            int idx = findChar(alphaCount, a);
            if (idx>=0) {
                res[idx].push_back(str);
            }else{
                vector<string> ele(1, str);
                res.push_back(ele);
                alphaCount.push_back(a);
            }
        }
        
        return res;
    }
};
