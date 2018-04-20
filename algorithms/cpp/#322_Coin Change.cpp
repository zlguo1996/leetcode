class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ans;
        ans.push_back(0);
        for(int i=1; i<=amount; i++){
            int minc = amount+1;
            for(int j=0; j<coins.size(); j++){
                if(i-coins[j]>=0) minc = min(minc, ans[i-coins[j]]+1);
            }
            ans.push_back(minc);
        }
        return ans[amount]>amount?-1:ans[amount];
    }
};
