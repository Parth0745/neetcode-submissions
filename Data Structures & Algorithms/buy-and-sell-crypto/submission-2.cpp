class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int minPrice=INT_MAX;
        // int ans=0;
        // int bestB=prices[0];
        // int maxProfit=0;
        // for(int i=1;i<prices.size();i++){
        //     ans=max(0,prices[i]-bestB);
        //     bestB=min(bestB,prices[i]);
        //     maxProfit=max(ans,maxProfit);

        // }
        // return maxProfit;

        int n = prices.size();
        int bestBuy = 0;
        int maxProfit = 0;
        for(int bestSell = 1;bestSell<n;bestSell++){
            if(prices[bestSell] < prices[bestBuy]){
                bestBuy = bestSell;
                continue;
            }
            int currProfit = prices[bestSell] - prices[bestBuy];
            maxProfit = max(maxProfit,currProfit);
        }

        return maxProfit;
    }
};
