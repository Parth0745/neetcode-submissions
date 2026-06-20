class Solution {
public:
    void dfs(vector<vector<int>>& heights, int i, int j, int val, vector<vector<bool>> &visited){
        int m = heights.size(), n = heights[0].size();
        if( i<0 || i>=m || j<0 || j>=n || val > heights[i][j] || visited[i][j] ) return;
        visited[i][j] = true;
        dfs(heights, i-1, j , heights[i][j], visited);
        dfs(heights, i, j+1 , heights[i][j], visited);
        dfs(heights, i, j-1 , heights[i][j], visited);
        dfs(heights, i+1, j , heights[i][j], visited);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> visited1(m, vector<bool> (n,false));
        vector<vector<bool>> visited2(m, vector<bool> (n,false)) ;
        vector<vector<int>> ans;

        for( int i = 0 ; i < m ; i++ ){
            dfs(heights, i, 0, heights[i][0], visited1);
            dfs(heights, i, n-1, heights[i][n-1], visited2);
        }

        for( int j = 0 ; j < n ; j++ ){
            dfs(heights, 0, j , heights[0][j], visited1);
            dfs(heights, m-1, j , heights[m-1][j], visited2);
        }

        for( int i = 0; i<m ; i++){
            for( int j = 0; j< n ; j++){
                if( visited1[i][j] && visited2[i][j] ) ans.push_back({i,j});
            }
        }

        return ans;
    }
};
