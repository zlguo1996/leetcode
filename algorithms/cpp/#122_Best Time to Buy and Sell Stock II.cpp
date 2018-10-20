class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int last;
        if(prices.size()>0) last = prices[0]; 
        for(int i=1; i<prices.size(); i++){
            int off = prices[i]-last;
            if(off>0) res += off;
            last = prices[i];
        }
        return res;
    }
};
