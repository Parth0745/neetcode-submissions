class Solution {
public:
    int area(vector<vector<int>>& grid,int i,int j){
        int m=grid.size(),n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        int left=area(grid,i,j-1);
        int right=area(grid,i,j+1);
        int top=area(grid,i-1,j);
        int bottom=area(grid,i+1,j);
        return 1+left+right+top+bottom;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    maxArea=max(maxArea,area(grid,i,j));
                }
            }
        }
        return maxArea;
    }
};
