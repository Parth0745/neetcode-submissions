class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pref(n,1);
        unordered_map<int,int> mp;
        int sum=0;
        int count=0;
        mp[0]=1;
        for(int x:nums){
            sum+=x;
            if(mp.find(sum-k)!=mp.end()){
                count+=mp[sum-k];
            }
            mp[sum]++;
        }
        return count;

    }
};