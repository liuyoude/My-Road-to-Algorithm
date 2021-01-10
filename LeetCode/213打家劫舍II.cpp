class Solution {
public:
    int rob(vector<int>& nums) {
        // ��̬�滮��dp����
        // dp[i]��ʾ�ӵ�i�ҿ�ʼ��ٵ������
        // dp[i] = max(dp[i+1], nums[i] + dp[i+2])
        // ������β���������Է�Ϊ�����������β���������ײ�����β��������β�������϶�û�к����ֺã�
        
        //���ֻ��һ�����ݣ����ÿ�����β
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
