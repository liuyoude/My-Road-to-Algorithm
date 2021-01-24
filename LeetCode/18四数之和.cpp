class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //������
        sort(nums.begin(), nums.end());

        vector< vector<int> > res;
        // �������飬ת��Ϊ������
        for(int i = 0; i < nums.size(); i ++){
            int threeTarget = target - nums[i];
            vector< vector<int> > threeRes = threeSum(nums, i + 1, threeTarget);
            for(int j = 0; j < threeRes.size(); j ++){
                vector<int> fourSig = threeRes[j];
                fourSig.push_back(nums[i]);
                res.push_back(fourSig);
            }
            // �����ظ���
            while(i < nums.size() - 1 && nums[i] == nums[i + 1]) i ++;
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums, int start, int target) {

        vector< vector<int> > res;
        // ����������Ϊ��һ����
        for(int i = start; i < nums.size(); i ++){
            // ����������Ϊtarget����
            int twoTarget = target - nums[i];
            vector< vector<int> > twoRes = twoSum(nums, i+1, twoTarget);
            for(int j = 0; j < twoRes.size(); j ++){
                vector<int> threeRes = twoRes[j];
                threeRes.push_back(nums[i]);
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
