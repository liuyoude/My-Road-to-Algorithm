class Solution {
public:
    int rob(vector<int>& nums) {
        // ��̬�滮��������¼�ĵݹ�
        // dp(nums, i) ��ʾ�ӵ�i�俪ʼ��ٵ���߽��
        // dp(nums, i) = max(dp(nums, i+1), nums[i]+dp(nums, i+2))
        vector<int> memo(nums.size(), -1);
        return dp(nums, 0, memo);

    }

    int dp(vector<int>& nums, int i, vector<int>& memo){
        // base case
        if(i >= nums.size()) return 0;
        // ����¼
        if(memo[i] != -1) return memo[i];
        // ״̬ת�Ʒ���
        int res = max(dp(nums, i+1, memo), nums[i] + dp(nums, i+2, memo));
        memo[i] = res;
        return res;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        // ��̬�滮��dp����
        // dp[i]��ʾ�ӵ�i�ҿ�ʼ��ٵ������
        // dp[i] = max(dp[i+1], nums[i] + dp[i+2])
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size() + 2);
        for(int i = nums.size() - 1; i >= 0; i --){
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        }
        return dp[0];
    }
};
