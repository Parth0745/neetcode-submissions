class Solution {
public:
    void helper(int i,vector<int>& nums,vector<int> &curr,vector<vector<int>> &ans,int target){
        if(target==0) {ans.push_back(curr); return;}
        if(i==nums.size() || target<0) return;
        // if(i!=0 &&nums[i]!nums[i-1])
        curr.push_back(nums[i]);
        helper(i+1,nums,curr,ans,target-nums[i]);
        curr.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        helper(i+1,nums,curr,ans,target);
        // target-=nums[i];
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        helper(0,nums,curr,ans,target);
        // vector<vector<int>> ans1(ans.begin(),ans.end());
        return ans;
    }
};
