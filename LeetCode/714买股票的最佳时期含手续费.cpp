class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // ��̬�滮
        // dp[i][k][0 or 1]��ʾ��i������k�ν��׻������ϳ��У�1����δ���У�0����Ʊʱ���������
        // ״̬ת�Ʒ�������(����С��)��
        // dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + price[i]), ǰһ��δ���л���ǰһ����е�������
        // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - price[i] - fee), ǰһ���ѳ��У�����ǰһ��δ���е�������
        // ���ڲ����ƽ��״�����k��k-1��״̬ʵ��������ͬ�ģ�
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i])
        // dp[i][1] = max(dp[i-1][1], d[i-1][0] - price[i])])
        // base case���£�
        // dp[0][0] = 0
        // dp[0][1] = -price[0] - fee
        // return dp[i][0]; ��Ȼ���һ���������й�Ʊ���������
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


