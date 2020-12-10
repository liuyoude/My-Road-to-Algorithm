#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

def binary_search(vector<int> nums, int target){
	// ��������Ϊ[left, right] 
	int left = 0, right = nums.size()-1;
	// left = right + 1ʱ����ѭ��
	while(left <= right){
		// ��ֹԽ�� 
		int mid = left + (right - left) / 2;
		if(nums[mid] < target){
			left = mid + 1;
		} else if(nums[mid] > target){
			right = mid - 1;
		} else{
			return mid;
		}
	} 
	return -1;
	
}

int left_bound(vector<int> nums, int target){
	int left = 0, right = nums.size()-1;
	while(left <= right){
		int mid = left + (right - left) / 2;
		if(nums[mid] < target){
			left = mid + 1;
		}
		else if(nums[mid] > target){
			right = mid - 1;
		}
		else{
			// �������߽�
			right = mid - 1; 
		}
	}
	// ���left�Ƿ�Խ��
	if(left >= nums.size() || nums[left] != target){
		return -1;
	} 
	return left;
}

int right_bound(vector<int> nums, int target){
	int left = 0, right = nums.size()-1;
	while(left <= right){
		int mid = left + (right - left) / 2;
		if(nums[mid] < target){
			left = mid + 1;
		}
		else if(nums[mid] > target){
			right = mid - 1;
		}
		else{
			// �����ұ߽�
			left = mid + 1; 
		}
	}
	if(right < 0 || nums[right] != target) return -1;
	return right; 
}

int main(){
	
	return 0;
} 
