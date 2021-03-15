/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return bulid(nums, 0, nums.size()-1);

    }

    TreeNode* bulid(vector<int>& nums, int left, int right){
        if(left > right) return nullptr;
        // Ѱ�����ֵ��Ϊ���ڵ�
        int maxValue = nums[left]; 
        int index = left;
        for(int i = left+1; i <= right; ++ i){
            if(nums[i] > maxValue){
                maxValue = nums[i];
                index = i;
            } 
        }

        TreeNode* root = new TreeNode(maxValue);
        // ���������Ϊ���������ұ�������Ϊ������
        root->left = bulid(nums, left, index-1);
        root->right = bulid(nums, index+1, right);
        return root;

    }
};
