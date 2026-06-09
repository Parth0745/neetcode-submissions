class Solution {
public:
    // int dfs(vector<vector<int>>& grid,int i, int j){
    //     int m=grid.size(), n= grid[0].size();
    //     if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==-1){
    //         return INT_MAX-2;
    //     }
    //     if(grid[i][j]==0) return 1;
    //     return 1+min({dfs(grid,i-1,j),dfs(grid,i+1,j),dfs(grid,i,j+1),dfs(grid,i,j-1)}); 
    // }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size(), n= grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        vector<pair<int,int>> dir={{1,0},{0,1},{-1,0},{0,-1}};

        while(!q.empty()){
            auto [i,j]= q.front();
            q.pop();

            for(auto &[dx,dy]: dir){
                int nx=dx+i;
                int ny=dy+j;

                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==INT_MAX){
                    grid[nx][ny]=grid[i][j]+1;
                    q.push({nx,ny});
                }
            }
        }

        
    }
};
