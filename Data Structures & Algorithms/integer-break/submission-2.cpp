class Solution {
public:
    vector<int> dp;
    int helper(int n){
        if( n == 1) return 1;
        if(dp[n] != -1) return dp[n];
        int ans = 0;
        for(int i = 1 ; i <= n-1 ; i++){
            int notBreak = i*(n-i);
            int withBreak = i*helper(n-i);
            ans = max({ans,notBreak, withBreak});
        }   
        return dp[n] = ans;
    }
    int integerBreak(int n) {
        dp.resize(n+1, -1);
        dp[1] = 1;
        for( int i = 2 ; i <= n ; i++){
            for(int j = 1 ; j <= i-1 ; j++){
                int notBreak = j*(i-j);
                int withBreak = j*dp[i-j];
                dp[i] = max({dp[i], notBreak, withBreak});
            }
        }
        return dp[n];
    }
};