class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();

        unordered_map<int,int> mp;
        int l = 0;

        for(int r = 0;r<n;r++){
            if(r-l>k){
                mp.erase(nums[l]);
                l++;
            }

            if(mp.count(nums[r])){
                return true;
            }
            mp[nums[r]] ++;
        }

        return false;
    }
};