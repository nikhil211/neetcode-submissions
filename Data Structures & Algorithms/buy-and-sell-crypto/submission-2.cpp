class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int len = prices.size();

        if(len == 1) return 0;
        int r = 1;
        int maxP = 0;

        while(r < len) {
            if(prices[l] < prices[r])
                maxP = max(maxP, prices[r] - prices[l]);
            else 
                l = r;
            r++;;
        }
        return maxP;

    }
};
