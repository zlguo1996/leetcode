class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if(k==0){
            res.push_back(vector<int>());
            return res;
        }
        for(int i=n; i>=k; i--){
            vector<vector<int>> subRes = combine(i-1, k-1);
            for(auto subVec:subRes){
                subVec.push_back(i);
                res.push_back(subVec);
            }
        }
        
        return res;
    }
};
