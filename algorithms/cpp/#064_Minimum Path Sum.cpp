class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int r=1; r<grid.size(); r++) grid[r][0] += grid[r-1][0];
        for (int c=1; c<grid[0].size(); c++) grid[0][c] += grid[0][c-1];
        
        for (int r=1; r<grid.size(); r++) {
            for (int c=1; c<grid[0].size(); c++) {
                grid[r][c] += min(grid[r-1][c], grid[r][c-1]);
            }
        }
        
        return grid[grid.size()-1][grid[0].size()-1];
    }
};
