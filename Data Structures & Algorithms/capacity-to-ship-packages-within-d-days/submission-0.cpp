class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int mini=INT_MIN;
        int sum=0;
        for(int x:weights){
            mini=max(x,mini);
            sum+=x;
        }
        int l=mini,r=sum;
        while(l<=r){
            int mid=l+(r-l)/2;
            int day=1,load=0;
            for(int x:weights){
                if(x+load>mid){
                    day++;
                    load=x;
                }
                else{
                    load+=x;
                }
            }
            if(day<=days){
                r=mid-1;
            }
            else if(day>days){
                l=mid+1;
            }
        }
        return l;

    }
};