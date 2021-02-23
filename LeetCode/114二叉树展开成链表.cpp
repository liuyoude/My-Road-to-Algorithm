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
        // չ��������
        flatten(root->left);
        // չ��������
        flatten(root->right);
        TreeNode* rightNode = root->right;
        // �������滻��������
        root->right = root->left;
        // ������null
        root->left = nullptr;
        // �滻���������������ף�����ԭ����������
        while(root->right != nullptr){
            root = root->right;
        }
        root->right = rightNode;
    }
};
