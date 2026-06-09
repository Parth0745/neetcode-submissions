class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& grid){
        int m=grid.size(),n=grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]=='0') return;
        grid[i][j]='0';
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0;
        vector<pair<int,int>> dir={{0,-1},{-1,0},{1,0},{0,1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    queue<pair<int,int>> cell;
                    cell.push({i,j});
                    grid[i][j]='0';
                    while(!cell.empty()){
                        auto it=cell.front();
                        cell.pop();
                        for(auto it1:dir){
                            int nx=it.first+it1.first;
                            int ny=it.second+it1.second;
                            if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]=='1'){
                                cell.push({nx,ny});
                                grid[nx][ny]='0';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
