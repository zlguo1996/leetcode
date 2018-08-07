class Solution {
public:
    int findRow(vector<vector<int>>& matrix, int r1, int r2, int target){
        while(r1<r2){
            int mid = (r1+r2)/2;
            int middle = mid==matrix.size()?INT_MAX:matrix[mid][0];
            if(target<middle) r2=mid;
            else r1=mid+1;
        }
        return r1;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        if(n==0) return false;
        
        int row = findRow(matrix, 0, m, target)-1;
        if(row==-1||matrix[row][n-1]<target) return false;
        else return binary_search(matrix[row].begin(), matrix[row].end(), target);
    }
};
