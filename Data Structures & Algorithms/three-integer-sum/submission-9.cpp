class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // vector<vector<int>> ans;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(i>0 && nums[i-1]==nums[i]) continue;
        //     int target=-(nums[i]);
        //     int j=i+1,k=n-1;
        //     // vector<int> a;
        //     while(j<k){
        //         if(nums[j]+nums[k]<target){
        //             j++;
        //         }
        //         else if(nums[j]+nums[k]>target){
        //             k--;
        //         }
        //         else{
                    
        //             ans.push_back({nums[i],nums[j],nums[k]});
        //             j++,k--;
        //             while(j<k && nums[j]==nums[j-1]) j++;
        //             while(j<k && nums[k]==nums[k+1]) k++;
        //         }
        //     }
        //     // while(i<nums.size()-1 && nums[i+1]==nums[i]){
        //     //     i++;
        //     // }
        // }
        // return ans;
















        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=n-1;
            // vector<int> v;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++,k--;
                    while(j<k&&nums[j]==nums[j-1]) j++;
                    while(j<k&&nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};
