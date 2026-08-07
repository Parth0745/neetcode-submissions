class Solution {
public:
    string s1;
    string s2;
    string s3;
    bool helper(int i, int j,int m, int n,vector<vector<int>> &dp){
        if( i == m && j == n ) return true;
        if(i<m && j < n){
            if(dp[i][j] != -1) return dp[i][j];
            if((s1[i] != s3[i+j]) && (s2[j] != s3[i+j])) return dp[i][j] = false;
        }
        else if( i<m ){
            while( i<m ){
                if(s1[i] != s3[i+j]) return dp[i][j] = false;
                i++;
            }
            return dp[i][j] = true;
        }
        else if( j<n ){
            while( j<n ){
                if(s2[j] != s3[i+j]) return dp[i][j] = false;
                j++;
            }
            return dp[i][j] = true;
        }
        
        if((s1[i] == s3[i+j]) && (s2[j] == s3[i+j])) return dp[i][j] = helper(i+1,j,m,n,dp) || helper(i,j+1,m,n,dp);
        else if(s1[i] == s3[i+j]) return dp[i][j] = helper(i+1,j,m,n,dp);
        else if(s2[j] == s3[i+j]) return dp[i][j] = helper(i,j+1,m,n,dp);
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size() , n = s2.size();
        this->s1 = s1;
        this->s2 = s2;
        this->s3 = s3;
        vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
        if( m+n != s3.size() ) return false;
        // if()
        return helper(0,0, s1.size(), s2.size(),dp);
    }
};
