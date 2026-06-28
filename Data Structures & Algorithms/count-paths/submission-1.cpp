class Solution {
public:
    int helper(int i, int j,int m, int n, vector<int> &dp){
        if ( i==0 && j==0 ){
            return 1;
        }
        if( i<0 || j<0 || i>=m || j>=n) return 0;
        if( dp[j] != -1 ) return dp[j];
        int up = helper(i-1,j,m,n,dp);
        int left = helper(i,j-1,m,n,dp);
        return dp[j] = left + up;

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,1));
        // return helper(m-1,n-1,m,n,dp);
        for(int i = 1; i < m; i++){
            for( int j = 1 ; j < n ; j++){
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
