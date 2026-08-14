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
        return helper(n);
    }
};