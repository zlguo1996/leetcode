class Solution {
public:
    vector<string> gp(int n, int left, int right){
        vector<string> result;
        
        if(right==n&&left==n) result.push_back("");
        else if(right<n&&left==n) {
            for(auto i:gp(n,left,right+1)) result.push_back(")"+i);
        }
        else{
            if(right==left) {
                for(auto i:gp(n,left+1,right)) result.push_back("("+i);
            }
            else{
                for(auto i:gp(n,left,right+1)) result.push_back(")"+i);
                for(auto i:gp(n,left+1,right)) result.push_back("("+i);
            }
        }
        
        return result;
    }
    vector<string> generateParenthesis(int n) {
        return gp(n, 0, 0);
    }
};
