class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        // �������� ���߽����� 
        int left = left_bound(nums, target);
        // �������� �Ҳ�߽����� 
        int right = right_bound(nums, target);
        result[0] = left;
        result[1] = right;
        return result;
    }
    int left_bound(vector<int> nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
            	// �൱ʱ�����أ��̶����߽磬�����Ҳ�߽� 
                right = mid - 1;
            }
        }
        // ѭ������������ left=right+1,��Ҫ��ֹleft�Ҳ�Խ�� 
        if(left >= nums.size() || nums[left] != target ) return -1;
        return left;
    }
    int right_bound(vector<int> nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] < target){
            left = mid + 1;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
        	// ���ʱ�����أ��̶��Ҳ�߽磬�������߽� 
            left = mid + 1;
        }
    }
    // ѭ������������ left=right+1,��Ҫ��ֹright���Խ��
    if(right < 0 || nums[right] != target ) return -1;
    return right;
    }
};
