class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //先排序
        sort(nums.begin(), nums.end());

        vector< vector<int> > res;
        // 遍历数组，转化为三数和
        for(int i = 0; i < nums.size(); i ++){
            int threeTarget = target - nums[i];
            vector< vector<int> > threeRes = threeSum(nums, i + 1, threeTarget);
            for(int j = 0; j < threeRes.size(); j ++){
                vector<int> fourSig = threeRes[j];
                fourSig.push_back(nums[i]);
                res.push_back(fourSig);
            }
            // 跳过重复的
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i ++;
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {

        vector< vector<int> > res;
        // 遍历数组作为第一个数
        for(int i = start; i < nums.size(); i ++){
            // 计算两数和为target的数
            int twoTarget = target - nums[i];
            vector< vector<int> > twoRes = twoSum(nums, i+1, twoTarget);
            for(int j = 0; j < twoRes.size(); j ++){
                vector<int> threeRes = twoRes[j];
                threeRes.push_back(nums[i]);
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
