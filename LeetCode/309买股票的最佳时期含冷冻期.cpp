class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //?��̬�滮
????????//?dp[i][k][0?or?1]��ʾ��i������k�ν��׻������ϳ��У�1����δ���У�0����Ʊʱ���������
????????//?״̬ת�Ʒ������£������䶳���ڲ��ܽ��ף���
????????//?dp[i][k][0]?=?max(dp[i-1][k][0],?dp[i-1][k][1]?+?price[i]),?ǰһ��δ���л���ǰһ����е�������
????????//?dp[i][k][1]?=?max(dp[i-1][k][1],?dp[i-2][k-1][0]?-?price[i]),?ǰһ���ѳ��У������䶳�ڽ���������
????????//?���ڲ����ƽ��״�����k��k-1��״̬ʵ��������ͬ��,��
????????//?dp[i][0]?=?max(dp[i-1][0],?dp[i-1][1]?+?price[i])
????????//?dp[i][1]?=?max(dp[i-1][1],?d[i-2][0]?-?price[i])])
????????//?base?case���£�
????????//?dp[0][0]?=?0
????????//?dp[0][1]?=?-price[0]
????????//?return?dp[i][0];?��Ȼ���һ���������й�Ʊ���������
        int num_day = prices.size();
        if(num_day == 0) return 0;
        vector< vector<int> > dp(num_day, vector<int>(2));
        for(int i = 0; i < num_day; i ++){
            if(i == 0){
                dp[i][0] = 0;
                dp[i][1] = - prices[i];
            }else if(i == 1){
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], -prices[i]); 
            }else{
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
                dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
            }
        }
        return dp[num_day-1][0];
    }
};
