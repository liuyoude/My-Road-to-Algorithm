class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         // ��̬�滮
        // dp[i][k][0 or 1]��ʾ��i������k�ν��׻������ϳ��У�1����δ���У�0����Ʊʱ���������
        // ״̬ת�Ʒ������£�
        // dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + price[i]), ǰһ��δ���л���ǰһ����е�������
        // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - price[i]), ǰһ���ѳ��У�����ǰһ��δ���е�������
        // dp[i][0][0] = 0
        // base case���£�
        // dp[0][1][0] = 0
        // dp[0][2][0] = 0
        // ...
        // dp[0][1][1] = -price[0]
        // dp[0][2][1] = -price[0]
        // ...
        // return dp[i][0]; ��Ȼ���һ���������й�Ʊ���������
        int num_day = prices.size();
        int k_max = k;
        if(num_day == 0 || k_max == 0) return 0;
        // ��ֹdp���鱬�ڴ棬һ�ν������ٸ����죬��k_max>����/2ʱ���൱��k=inf
        if(k_max > prices.size() / 2) return maxProfit_inf_k(prices);
        vector< vector< vector<int> > > dp(num_day, vector< vector<int> >(k_max+1, vector<int>(2))); 
        for(int i = 0; i < num_day; i ++){
            // base case
            if(i == 0){
                for(int k = k_max; k >= 1; k --){
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                }
            }else{
                for(int k = k_max; k >= 1; k --){
                    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
                }
            }
        }
        return dp[num_day - 1][k_max][0];
    }
    int maxProfit_inf_k(vector<int>& prices) {
        // ��̬�滮
        // dp[i][k][0 or 1]��ʾ��i������k�ν��׻������ϳ��У�1����δ���У�0����Ʊʱ���������
        // ״̬ת�Ʒ������£�
        // dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + price[i]), ǰһ��δ���л���ǰһ����е�������
        // dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - price[i]), ǰһ���ѳ��У�����ǰһ��δ���е�������
        // ���� k = 1, 
        // dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + price[i])
        // dp[i][1][1] = max(dp[i-1][1][1], -price[i]), dp[i-1][0][0]=0,���ܽ��н��ף�������ȻΪ0
        // ��ת�Ʒ��̲��ܽ��״���״̬Ӱ�죬���Լ�Ϊ��
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + price[i])
        // dp[i][1] = max(dp[i-1][1], -price[i])
        // base case���£�
        // dp[0][0] = 0
        // dp[0][1] = -price[0]
        // return dp[i][0]; ��Ȼ���һ���������й�Ʊ���������
        int num_day = prices.size();
        if(num_day == 0) return 0;
        vector< vector<int> > dp(num_day, vector<int>(2));
        for(int i = 0; i < num_day; i ++){
            if(i == 0){
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
            }
            else{
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], - prices[i]);
            }
        }
        return dp[num_day-1][0];
    }
};


