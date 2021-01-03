class Solution {
public:
    int rob(vector<int>& nums) {
        // 动态规划：带备忘录的递归
        // dp(nums, i) 表示从第i间开始打劫的最高金额
        // dp(nums, i) = max(dp(nums, i+1), nums[i]+dp(nums, i+2))
        vector<int> memo(nums.size(), -1);
        return dp(nums, 0, memo);

    }

    int dp(vector<int>& nums, int i, vector<int>& memo){
        // base case
        if(i >= nums.size()) return 0;
        // 备忘录
        if(memo[i] != -1) return memo[i];
        // 状态转移方程
        int res = max(dp(nums, i+1, memo), nums[i] + dp(nums, i+2, memo));
        memo[i] = res;
        return res;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        // 动态规划：dp数组
        // dp[i]表示从第i家开始打劫的最大金额
        // dp[i] = max(dp[i+1], nums[i] + dp[i+2])
        if(nums.size() == 0) return 0;
        vector<int> dp(nums.size() + 2);
        for(int i = nums.size() - 1; i >= 0; i --){
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        }
        return dp[0];
    }
};
