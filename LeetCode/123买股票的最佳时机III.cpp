class Solution {
public:
    int maxProfit(vector<int>& prices) {
         // ��̬�滮
        // dp[i][k][0 or 1]��ʾ��i������k�ν��׻������ϳ��У�1����δ���У�0����Ʊʱ���������
        // ״̬ת�Ʒ������£�
        // dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + price[i]), ǰһ��δ���л���ǰһ����е�������
        // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - price[i]), ǰһ���ѳ��У�����ǰһ��δ���е�������
        // dp[i][0][0] = 0�� dp[i][0][1] = -inf(״̬ת�Ʒ����в���Ҫ��״̬)
        // base case���£�
        // dp[0][1][0] = 0
        // dp[0][2][0] = 0
        // dp[0][1][1] = -price[0]
        // dp[0][2][1] = -price[0]
        // return dp[i][0]; ��Ȼ���һ���������й�Ʊ���������
        int num_day = prices.size();
        vector< vector< vector<int> > > dp(num_day, vector< vector<int> >(2+1, vector<int>(2)));
        if(num_day == 0) return 0;
        for(int i = 0; i < num_day; i ++){
            // base case
            if(i == 0){
                for(int k = 2; k >= 1; k --){
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                }
            }else{
                for(int k = 2; k >= 1; k --){
                    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
                }
            }
        }
        return dp[num_day - 1][2][0];
    }
};


