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
        // 寻找最大值作为根节点
        int maxValue = nums[left]; 
        int index = left;
        for(int i = left+1; i <= right; ++ i){
            if(nums[i] > maxValue){
                maxValue = nums[i];
                index = i;
            } 
        }

        TreeNode* root = new TreeNode(maxValue);
        // 左边数组作为左子树，右边数组作为右子树
        root->left = bulid(nums, left, index-1);
        root->right = bulid(nums, index+1, right);
        return root;

    }
};
