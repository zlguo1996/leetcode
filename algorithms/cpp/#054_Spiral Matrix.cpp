class Solution {
public:
    enum DIRECTION{RIGHT, DOWN, LEFT, UP};
    bool moveToward(vector<vector<int>>& matrix, int& r, int& c, DIRECTION dir, vector<int>& res){
        int cur_r = r, cur_c = c;
        bool flag=false;
        switch (dir) {
            case RIGHT:
                while(cur_c<(int)matrix[0].size()-2-c){
                    res.push_back(matrix[cur_r][++cur_c]);
                    flag = true;
                }
                break;
                
            case DOWN:
                while (cur_r<(int)matrix.size()-1-r) {
                    res.push_back(matrix[++cur_r][cur_c]);
                    flag = true;
                }
                break;
                
            case LEFT:
                while (cur_c>(int)matrix[0].size()-1-c) {
                    res.push_back(matrix[cur_r][--cur_c]);
                    flag = true;
                }
                break;
                
            case UP:
                while (cur_r>(int)matrix.size()-r) {
                    res.push_back(matrix[--cur_r][cur_c]);
                    flag = true;
                }
                break;
        }
        r = cur_r;
        c = cur_c;
        return flag;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0) return res;
        
        int r=0, c=-1;
        while (1) {
            if(!moveToward(matrix, r, c, RIGHT, res)) break;
            if(!moveToward(matrix, r, c, DOWN, res)) break;
            if(!moveToward(matrix, r, c, LEFT, res)) break;
            if(!moveToward(matrix, r, c, UP, res)) break;
        }
        
        return res;
    }
};
