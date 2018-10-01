class Solution {
public:
    string vitos(vector<int>& ip){
        string res = to_string(ip[0]);
        for (int i=1; i<4; i++) {
            res = res+"."+to_string(ip[i]);
        }
        return res;
    }
    void IT(string s, int p, vector<int>& ip, vector<string>& res){
        if(ip.size()==4){
            if(p==s.size()) res.push_back(vitos(ip));
            return;
        }
        
        if(p<s.size()){
            ip.push_back(stoi(s.substr(p,1)));
            IT(s, p+1, ip, res);
            ip.erase(ip.end()-1);
        }else return;
        
        if(s[p]=='0') return;
        
        if (p<s.size()-1) {
            ip.push_back(stoi(s.substr(p,2)));
            IT(s, p+2, ip, res);
            ip.erase(ip.end()-1);
        }else return;
        
        if (p<s.size()-2) {
            int num = stoi(s.substr(p,3));
            if(num>255) return;
            ip.push_back(num);
            IT(s, p+3, ip, res);
            ip.erase(ip.end()-1);
        }else return;
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<int> ip;
        IT(s, 0, ip, res);
        return res;
    }
};
