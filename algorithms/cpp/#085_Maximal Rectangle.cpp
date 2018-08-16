class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int rn=matrix.size(), cn=matrix[0].size();
        vector<vector<int>> rm(rn, vector<int>(cn, 0)), cm(rn, vector<int>(cn, 0));
        vector<vector<int>> mm(rn, vector<int>(cn, 0));

        for (int r=0; r<rn; r++) {
            for (int c=0; c<cn; c++) {
                if (matrix[r][c]=='1'){
                    if(c==0) cm[r][c] = 0;
                    else if(matrix[r][c-1]=='1') cm[r][c] = cm[r][c-1];
                    else cm[r][c] = c;
                    
                    if(r==0) rm[r][c] = 0;
                    else if(matrix[r-1][c]=='1') rm[r][c] = rm[r-1][c];
                    else rm[r][c] = r;
                }
            }
        }
        
        int res=0;
        for (int r=0; r<rn; r++) {
            for (int c=0; c<cn; c++) {
                if(matrix[r][c]=='0') continue;
                int max_height = INT_MAX;
                for (int rs=r; rs>=rm[r][c]; rs--) {
                    max_height = min(c-cm[rs][c]+1, max_height);
                    mm[r][c] = max(max_height*(r-rs+1), mm[r][c]);
                }
                res = max(mm[r][c], res);
            }
        }
        
        return res;
    }
};
