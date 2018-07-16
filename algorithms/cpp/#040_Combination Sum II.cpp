class Solution {
public:
    vector<vector<int>> my_combinationSum(vector<int>& candidates, int c_idx, int target) {
        vector<vector<int>> res;
        for (int i=c_idx; i<candidates.size(); i++) {
            if (i>c_idx&&candidates[i]==candidates[i-1]) continue;
            if (target<candidates[i]) break;
            else if (target==candidates[i]) {
                vector<int> tmp;
                tmp.push_back(candidates[i]);
                res.push_back(tmp);
                break;
            }
            else{
                vector<vector<int>> tmp_res = my_combinationSum(candidates, i+1, target-candidates[i]);
                for (int j=0; j<tmp_res.size(); j++) {
                    tmp_res[j].push_back(candidates[i]);
                    res.push_back(tmp_res[j]);
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        return my_combinationSum(candidates, 0, target);
    }
};
