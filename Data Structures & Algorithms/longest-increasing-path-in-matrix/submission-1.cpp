class Solution {
public:
    int ans;
    int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &memo,int prevVal){
        if( i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || prevVal >= matrix[i][j] ) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        int left = dfs(i, j-1, matrix, memo, matrix[i][j]);
        int right = dfs(i, j+1, matrix, memo, matrix[i][j]);
        int top = dfs(i+1, j, matrix, memo, matrix[i][j]);
        int bottom = dfs(i-1, j, matrix, memo, matrix[i][j]);
        return memo[i][j] = 1 + max({left,right,top,bottom});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int> (n,-1));
        ans = 0;
        for(int i = 0 ; i < m ; i++){
            for( int j = 0 ; j < n ; j++){
                if(memo[i][j] != -1){
                    ans = max(ans, memo[i][j]);
                }
                else{
                    ans = max(ans, dfs(i,j,matrix,memo,INT_MIN));
                }
            }
        }
        return ans;
    }
};
