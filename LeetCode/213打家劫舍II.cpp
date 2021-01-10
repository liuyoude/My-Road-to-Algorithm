class Solution {
public:
    int rob(vector<int>& nums) {
        // 动态规划：dp数组
        // dp[i]表示从第i家开始打劫的最大金额
        // dp[i] = max(dp[i+1], nums[i] + dp[i+2])
        // 由于首尾相连，可以分为三种情况：首尾都不抢，首不抢，尾不抢（首尾都不抢肯定没有后两种好）
        
        //如果只有一个房屋，不用考虑首尾
        if(nums.size() == 1) return nums[0];
        return max(robrange(nums, 0, nums.size()-2), robrange(nums, 1, nums.size()-1));
    }
    int robrange(vector<int>& nums, int start, int end){
        vector<int> dp(nums.size()+2);
        for(int i = end; i >= start; i --){
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        }
        return dp[start];
    }
};
