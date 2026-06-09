class Solution {
public:
    // int target=0;
    bool helper(int i,vector<bool> &vis,int currSum,int target,int k,vector<int>& nums){
        if(k==1) return true;
        if(currSum==target){
            return helper(0,vis,0,target,k-1,nums);
        }
        for(int j=i;j<nums.size();j++){
            if(vis[j]||currSum+nums[j]>target) continue;
            vis[j]=true;
            if(helper(j+1,vis,currSum+nums[j],target,k,nums)) return true;
            vis[j]=false;
            if(currSum == 0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k!=0) return false;
        sort(nums.rbegin(),nums.rend());
        if(nums[0]>sum/k) return false;
        int n=nums.size();
        vector<bool> vis(n,false);
        return helper(0,vis,0,sum/k,k,nums); 
    }
};