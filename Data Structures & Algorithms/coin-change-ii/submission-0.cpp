class Solution {
public:
    int target;
    int ans;
    int helper(int idx, int curr,vector<int>& coins,vector<vector<int>> &memo){
        if(curr == target){
            ans++;
            return 1;
        }
        if(idx >= coins.size()) return 0;
        if(memo[idx][curr]!=-1) return memo[idx][curr];
        int take = 0;
        if((target-curr) >= coins[idx]) take = helper(idx,curr+coins[idx],coins,memo);
        int notTake = helper(idx+1,curr,coins,memo);
        return memo[idx][curr] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        target = amount;
        ans = 0;
        vector<vector<int>> memo(coins.size()+1,vector<int> (amount+1,-1));
        return helper(0,0,coins,memo);
    }
};
