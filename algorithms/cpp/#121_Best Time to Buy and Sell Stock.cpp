class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<min) min = prices[i];
            if(prices[i]-min>res) res = prices[i]-min;
        }
        return res;
    }
};
