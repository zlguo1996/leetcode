class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.size()==0) {
            return result;
        }
        
        vector<vector<char>> dic;
        vector<char> dig0 = {' '};
        vector<char> dig1 = {'0'};
        vector<char> dig2 = {'a', 'b', 'c'};
        vector<char> dig3 = {'d', 'e', 'f'};
        vector<char> dig4 = {'g', 'h', 'i'};
        vector<char> dig5 = {'j', 'k', 'l'};
        vector<char> dig6 = {'m', 'n', 'o'};
        vector<char> dig7 = {'p', 'q', 'r', 's'};
        vector<char> dig8 = {'t', 'u', 'v'};
        vector<char> dig9 = {'w', 'x', 'y', 'z'};
        dic.push_back(dig0);
        dic.push_back(dig1);
        dic.push_back(dig2);
        dic.push_back(dig3);
        dic.push_back(dig4);
        dic.push_back(dig5);
        dic.push_back(dig6);
        dic.push_back(dig7);
        dic.push_back(dig8);
        dic.push_back(dig9);
        
        char c = digits[0];
        if(c-'0'>9||c-'0'<0){
            return result;
        }else{
            for(int i=0; i<dic[c-'0'].size(); i++){
                vector<string> r = letterCombinations(digits.substr(1));
                if(r.empty()) r.push_back("");
                for(int j=0; j<r.size(); j++){
                    result.push_back(string(&dic[c-'0'][i], 1)+r[j]);
                }
            }
        }
        
        return result;
    }
};
