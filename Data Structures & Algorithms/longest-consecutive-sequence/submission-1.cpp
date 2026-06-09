class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int &x:nums){
            mp[x]++;
        }
        int len=0;
        int maxLen=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1)==mp.end()){
                len=1;
                while(mp.find(nums[i]+1)!=mp.end()){
                    len++;
                    nums[i]++;
                }
                maxLen=max(len,maxLen);
            }
        }
        return maxLen==INT_MIN?0:maxLen;
    }
};
