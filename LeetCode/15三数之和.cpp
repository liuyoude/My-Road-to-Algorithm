class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // ���������оٸ�Ϊ����������
        sort(nums.begin(), nums.end());

        vector< vector<int> > res;
        // ����������Ϊ��һ����
        for(int i = 0; i < nums.size(); i ++){
            // ����������Ϊtarget����
            int target = 0 - nums[i];
            vector< vector<int> > twoRes = twoSum(nums, i+1, target);
            for(int j = 0; j < twoRes.size(); j ++){
                vector<int> threeRes(3);
                threeRes[0] = nums[i];
                threeRes[1] = twoRes[j][0];
                threeRes[2] = twoRes[j][1];

                res.push_back(threeRes);
            }
            // �����ظ���
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
