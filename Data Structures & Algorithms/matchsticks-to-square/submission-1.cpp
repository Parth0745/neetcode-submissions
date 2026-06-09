class Solution {
public:
    int length;
    bool helper(int j,vector<int>& sides,vector<int>& nums){
        if(j==nums.size()) return true;

        for(int i=0;i<4;i++){
            if(sides[i]+nums[j]<=length){
                sides[i]+=nums[j];
                if(helper(j+1,sides,nums)) return true;
                sides[i]-=nums[j];//backtracking
            }
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%4!=0 || nums.size()<4) return false;
        sort(nums.begin(),nums.end(),[](auto &x,auto &y){
            return x>y;
        });
        if(nums[0]>(sum/4)) return false;
        length=sum/4;
        vector<int> sides(4,0);
        return helper(0,sides,nums);
    }
};