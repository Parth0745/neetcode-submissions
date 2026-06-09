class Solution {
public:
    void helper(int i,vector<int>& nums,vector<int> &curr,vector<vector<int>> &ans,int target){
        if(target==0) {ans.push_back(curr); return;}
        if(i==nums.size() || target<0) return;
        curr.push_back(nums[i]);
        helper(i,nums,curr,ans,target-nums[i]);
        curr.pop_back();
        helper(i+1,nums,curr,ans,target);
        // target-=nums[i];
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        helper(0,nums,curr,ans,target);
        return ans;
    }
};
