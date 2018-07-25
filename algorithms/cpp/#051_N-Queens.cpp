class Solution {
public:
    vector<int> availIdx(int n, vector<int>& prev){
        vector<int> res;
        int cur_row = (int)prev.size();
        
        vector<bool> idx(n, true);
        for(int i=0; i<prev.size(); i++){
            int col = prev[i];
            idx[col] = false;
            if(col-(cur_row-i)>=0) idx[col-(cur_row-i)] = false;
            if(col+(cur_row-i)<n) idx[col+(cur_row-i)] = false;
        }
        
        for (int i=0; i<idx.size(); i++) {
            if(idx[i]) res.push_back(i);
        }
        
        return res;
    }
    vector<vector<int>> solveNextLine(int n, vector<int>& prev){
        vector<vector<int>> res;
        if(prev.size()==n) res.push_back(prev);
        else {
            vector<int> avail = availIdx(n, prev);
            for(auto col:avail){
                prev.push_back(col);
                vector<vector<int>> tmp = solveNextLine(n, prev);
                prev.erase(prev.end()-1);
                
                for(auto ctnt:tmp){
                    res.push_back(ctnt);
                }
            }
        }
        return res;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> prev;
        vector<vector<int>> res_i = solveNextLine(n, prev);
        
        vector<vector<string>> res;
        for (int i=0; i<res_i.size(); i++) {
            vector<string> sol;
            for (int r=0; r<n; r++) {
                string row;
                for(int c=0; c<n; c++){
                    if(c==res_i[i][r]) row += 'Q';
                    else row += '.';
                }
                sol.push_back(row);
            }
            res.push_back(sol);
        }
        
        return res;
    }
};
