class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        // 二分搜索 左侧边界搜索 
        int left = left_bound(nums, target);
        // 二分搜索 右侧边界搜索 
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
            	// 相当时不返回，固定左侧边界，收缩右侧边界 
                right = mid - 1;
            }
        }
        // 循环结束条件是 left=right+1,需要防止left右侧越界 
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
        	// 相等时不返回，固定右侧边界，收缩左侧边界 
            left = mid + 1;
        }
    }
    // 循环结束条件是 left=right+1,需要防止right左侧越界
    if(right < 0 || nums[right] != target ) return -1;
    return right;
    }
};
