class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int x:piles){
            maxi=max(maxi,x);
        }
        int l=1,r=maxi;
        int ans=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            long long curr=0;
            for(int x:piles){
                curr+=(x + mid - 1) / mid;;
            }
            if(curr<=h){ 
                // ans=min(mid,ans); no need for this at the end l will give the ans
                r=mid-1;
            }
            else{
                l=mid+1;
            }
             
        }
        return l;
    }
};
