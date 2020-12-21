class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 动态规划
        // dp[i][k][0 or 1]表示在i天内有k次交易机会手上持有（1）或未持有（0）股票时的最大收益
        // 状态转移方程如下：
        // dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + price[i]), 前一天未持有或者前一天持有当天卖出
        // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - price[i]), 前一天已持有，或者前一天未持有当天买入
        // 带入 k = 1, 
        // dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + price[i])
        // dp[i][1][1] = max(dp[i-1][1][1], -price[i]), dp[i-1][0][0]=0,不能进行交易，利润自然为0
        // 该转移方程不受交易次数状态影响，可以简化为：
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i])
        // dp[i][1] = max(dp[i-1][1], -price[i])
        // base case如下：
        // dp[0][0] = 0
        // dp[0][1] = -price[0]
        // return dp[i][0]; 显然最后一天卖出持有股票是最大利润
        // int num_day = prices.size();
        // if(num_day == 0) return 0;
        // vector< vector<int> > dp(num_day, vector<int>(2));
        // for(int i = 0; i < num_day; i ++){
        //     if(i == 0){
        //         dp[i][0] = 0;
        //         dp[i][1] = -prices[i];
        //     }
        //     else{
        //         dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        //         dp[i][1] = max(dp[i-1][1], - prices[i]);
        //     }
        // }
        // return dp[num_day-1][0];

        // 用一个变量记录当前天数之前最低价格min_price，寻找price[i]-min_price的最大值
        int num_day = prices.size();
        int min_price = float('inf'), max_profit = 0;
        for(int i = 0; i < num_day; i ++){
            if(prices[i] < min_price) min_price = prices[i];
            if(prices[i] - min_price > max_profit) max_profit = prices[i] - min_price;
        }
        return max_profit;

    }
};
