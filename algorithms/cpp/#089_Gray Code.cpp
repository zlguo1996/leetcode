class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(n==0) return res;
        
        int level = 0, base = 1;
        while(level<n){
            int cap = res.size();
            for (int i=cap-1; i>=0; i--) {
                res.push_back(base+res[i]);
            }
            base *= 2;
            level++;
        }
        return res;
    }
};
