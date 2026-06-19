class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));
        for(int i = 0 ; i < m ; i ++){
            for( int j = 0 ; j < n ; j++){
                if(grid[i][j]==2){ q.push({i,j});
                vis[i][j]=1;}
            }
        }

        vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            for( int i = 0 ; i< size; i ++){
                auto pos = q.front(); q.pop();
                for( auto it: dir){
                    int nr = pos.first + it.first;
                    int nc = pos.second + it.second;
                    if(( nr < m && nr>=0 ) && (nc>=0 && nc < n) && (vis[nr][nc] == 0) && grid[nr][nc]==1){
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                        grid[nr][nc]=2;
                    }
                }
            }
            if(!q.empty()) ans++;
        }

        for(int i = 0 ; i < m ; i ++){
            for( int j = 0 ; j < n ; j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};
