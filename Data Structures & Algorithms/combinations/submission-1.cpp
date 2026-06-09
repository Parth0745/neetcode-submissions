class Solution {
public:
    void helper(int a,int end,vector<int> &curr,vector<vector<int>> &ans,int k){
        if(curr.size()==k){ ans.push_back(curr); return;}
        // if(a>end) return;
        // PRUNING
        if ((end - a + 1) < (k - curr.size())) return;
        curr.push_back(a);
        helper(a+1,end,curr,ans,k);
        curr.pop_back();
        helper(a+1,end,curr,ans,k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
       helper(1,n,curr,ans,k);
        return ans;
    }
};