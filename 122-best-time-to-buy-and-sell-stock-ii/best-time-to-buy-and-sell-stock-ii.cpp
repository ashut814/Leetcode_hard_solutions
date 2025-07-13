class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int max_profit = 0;
        for(int i = 1; i < size; i++){
            if(prices[i] > prices[i-1]){
                max_profit += prices[i] - prices[i-1];
            }
        }
        return max_profit;
    }
};


// [7,1,5,3,6,4]

// (buy at day2 and sold at day3) 1,5 => 4

// (buy at day 4 and sold at day5) 3, 6 => 3

// max profit = 3+4

// [1,2,3,4,5]

// buy at day 1 and sell it day 5

// => 4




