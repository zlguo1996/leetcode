class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> lis;
        
        for (int i=0; i<s.size(); i++) {
            int c = s[i]=='('?1:0;
            
            if (lis.empty()) {
                lis.push_back(c);
            }else{
                // 之前有‘（’且当前为‘）’
                if(lis.back()%2==1&&c==0){
                    lis.back() += 1;
                    while (lis.size()>1&&*(lis.end()-2)!=0&&*(lis.end()-2)%2==0) {
                        *(lis.end()-2) += lis.back();
                        lis.erase(lis.end()-1);
                    }
                    if (lis.size()>1&&*(lis.end()-2)%2==1) {
                        *(lis.end()-2) += lis.back();
                        lis.erase(lis.end()-1);
                    }
                }else{
                    lis.push_back(c);
                }
            }
        }
        
        int res = 0;
        for(auto i:lis){
            if(i>res) res = i;
        }
        res = res-res%2;
        
        return res;
    }
};
