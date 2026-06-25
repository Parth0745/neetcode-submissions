class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        minHeap.push({grid[0][0],{0,0}});
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> seen(m, vector<int> (n,0));
        vector<pair<int,int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
        while(!minHeap.empty()){
            auto [mini, point] = minHeap.top(); minHeap.pop();
            auto [x,y] = point;
            if(seen[x][y]) continue;
                    seen[x][y] = 1;
            if( x==m-1 && y == n-1) return mini;
            for(auto [a,b]: dir){
                int nr = x+a;
                int nc = y+b;
                if(min(nr,nc)>=0 && max(nr,nc)<n && !seen[nr][nc]){
                    minHeap.push({max(mini,grid[nr][nc]),{nr,nc}});
                }
            }
        }
        return -1;
    }
};
