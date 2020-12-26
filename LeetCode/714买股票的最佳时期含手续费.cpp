class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // 动态规划
        // dp[i][k][0 or 1]表示在i天内有k次交易机会手上持有（1）或未持有（0）股票时的最大收益
        // 状态转移方程如下(包含小费)：
        // dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + price[i]), 前一天未持有或者前一天持有当天卖出
        // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - price[i] - fee), 前一天已持有，或者前一天未持有当天买入
        // 由于不限制交易次数，k与k-1的状态实际上是相同的：
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i])
        // dp[i][1] = max(dp[i-1][1], d[i-1][0] - price[i])])
        // base case如下：
        // dp[0][0] = 0
        // dp[0][1] = -price[0] - fee
        // return dp[i][0]; 显然最后一天卖出持有股票是最大利润
        int num_day = prices.size();
        vector< vector<int> > dp(num_day, vector<int>(2));
        for(int i = 0; i < num_day; i ++){
            if(i == 0){
                dp[i][0] = 0;
                dp[i][1] = -prices[i] - fee;
            }else{
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee);
            }
            
        }
        return dp[num_day - 1][0];
    }
};


