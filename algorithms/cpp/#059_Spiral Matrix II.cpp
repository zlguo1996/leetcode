class Solution {
public:
    bool fillNext(int& r, int& c, int dir, int& cur_num, vector<vector<int>>& res){
        switch (dir) {
            case 0:
                if(c+1<res.size() && res[r][c+1]==0)  res[r][++c]=++cur_num;
                else return false;
                break;
            case 1:
                if(r+1<res.size() && res[r+1][c]==0)  res[++r][c]=++cur_num;
                else return false;
                break;
            case 2:
                if(c-1>=0 && res[r][c-1]==0)  res[r][--c]=++cur_num;
                else return false;
                break;
            case 3:
                if(r-1>=0 && res[r-1][c]==0)  res[--r][c]=++cur_num;
                else return false;
                break;
        }
        return true;
    }
    void changeDir(int& dir){
        if(++dir==4) dir = 0;
    }
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        
        int dir = 0;
        int r=0, c=-1;
        int num = 0;
        while(1){
            if(fillNext(r, c, dir, num, res)) ;
            else {
                changeDir(dir);
                if(!fillNext(r, c, dir, num, res)) break;
            }
        }
        return res;
    }
};
