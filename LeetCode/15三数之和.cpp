class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 数组排序列举改为二数和问题
        sort(nums.begin(), nums.end());

        vector< vector<int> > res;
        // 遍历数组作为第一个数
        for(int i = 0; i < nums.size(); i ++){
            // 计算两数和为target的数
            int target = 0 - nums[i];
            vector< vector<int> > twoRes = twoSum(nums, i+1, target);
            for(int j = 0; j < twoRes.size(); j ++){
                vector<int> threeRes(3);
                threeRes[0] = nums[i];
                threeRes[1] = twoRes[j][0];
                threeRes[2] = twoRes[j][1];

                res.push_back(threeRes);
            }
            // 跳过重复的
            while(i < nums.size()-1 && nums[i] == nums[i + 1]) i ++;

        }
        return res;

    }

    vector < vector<int> > twoSum(vector<int> nums, int start, int target){
        vector< vector<int> > res;
        int left = start;
        int right = nums.size() - 1;
        while(left < right){
            int sum = nums[left] + nums[right];
            int ln = nums[left];
            int rn = nums[right];
            if(sum < target){
                while(left < right && nums[left] == ln) left ++;
            }else if(sum > target){
                while(left < right && nums[right] == rn) right --;
            }else{
                vector<int> twoRes(2);
                twoRes[0] = nums[left];
                twoRes[1] = nums[right];
                res.push_back(twoRes);
                while(left < right && nums[left] == ln) left ++;
                while(left < right && nums[right] == rn) right --;
            }
        }
        return res;
    }
};
