class Solution {
public:
    int mySqrt(int x) {
        int low=1,high=x/2;
        int mid=0;
        if(!x) return 0;
        if(x==1) return 1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(mid==x/mid) return mid;
            else if(mid<x/mid){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};