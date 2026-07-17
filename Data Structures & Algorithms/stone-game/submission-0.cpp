class Solution {
public:
    bool helper(vector<int> &piles, int left, int right, int curr,int count, int target){
        if( count == (piles.size()/2) ) return curr > target;
        bool l = helper(piles, left + 1, right, curr + piles[left],count+1, target);
        bool r = helper(piles, left, right-1, curr+piles[right],count+1, target);
        return l||r;
    }
    bool stoneGame(vector<int>& piles) {
        // int sum = accumulate(piles.begin(), piles.end(),0);
        // sum/=2;
        // return helper(piles, 0, piles.size()-1, 0,0, sum);
        return true;
    }
};