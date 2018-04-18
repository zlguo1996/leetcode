class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(obstacleGrid[r][c]==1) obstacleGrid[r][c]=0;
                else if(r==0 && c==0) obstacleGrid[r][c]=1;
                else if(r==0) obstacleGrid[r][c]=obstacleGrid[r][c-1];
                else if(c==0) obstacleGrid[r][c]=obstacleGrid[r-1][c];
                else obstacleGrid[r][c] = obstacleGrid[r-1][c]+obstacleGrid[r][c-1];
            }
        }
        
        return obstacleGrid[rows-1][cols-1];
    }
};
