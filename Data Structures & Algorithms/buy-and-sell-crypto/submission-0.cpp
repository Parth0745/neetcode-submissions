class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int ans=0;
        int bestB=prices[0];
        int maxProfit=0;
        for(int i=1;i<prices.size();i++){
            ans=max(0,prices[i]-bestB);
            bestB=min(bestB,prices[i]);
            maxProfit=max(ans,maxProfit);

        }
        return maxProfit;
    }
};
