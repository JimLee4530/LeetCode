class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //solution 1
        int profit=0;
        // for(int i=1;i<prices.size();i++){
        //     if(prices[i]>prices[i-1])
        //         profit += prices[i]-prices[i-1];
        // }
        // return profit;
        
        // solution 2
        if(prices.size() == 0)
            return 0;
        int i = 0;
        int v = prices[0];
        int p = prices[0];
        while(i<prices.size()-1){
            while(i<prices.size()-1&&prices[i]>=prices[i+1])
                i++;
            v = prices[i];
            while(i<prices.size()-1&&prices[i]<=prices[i+1])
                i++;
            p = prices[i];
            profit += p-v;
        }
        return profit;
    }
};