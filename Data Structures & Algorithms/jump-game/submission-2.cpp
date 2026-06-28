class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi = 0;
        // int curr = nums[0];
        if ( nums[0] == 0 && nums.size()==1 ) return true;
        if ( nums[0] == 0 ) return false;
        for(int i = 0 ; i < nums.size(); i++){
            maxi = max(maxi, i + nums[i]);
            if ( nums[i] == 0 ){
                if ( i != nums.size()-1 && maxi == i) return false;
            }
        }
        return true;
    }
};
