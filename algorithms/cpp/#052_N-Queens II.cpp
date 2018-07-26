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
    int solveNextLine(int n, vector<int>& prev){
        int res=0;
        if(prev.size()==n) return 1;
        else {
            vector<int> avail = availIdx(n, prev);
            for(auto col:avail){
                prev.push_back(col);
                int tmp = solveNextLine(n, prev);
                prev.erase(prev.end()-1);
                
                res += tmp;
            }
        }
        return res;
    }
    int totalNQueens(int n) {
        vector<int> prev;
        return solveNextLine(n, prev);
    }
};c
