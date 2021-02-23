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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        // 展开左子树
        flatten(root->left);
        // 展开右子树
        flatten(root->right);
        TreeNode* rightNode = root->right;
        // 右子树替换成左子树
        root->right = root->left;
        // 左子树null
        root->left = nullptr;
        // 替换的右子树遍历到底，连接原本的右子树
        while(root->right != nullptr){
            root = root->right;
        }
        root->right = rightNode;
    }
};
