/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*, int> memo;
    int rob(TreeNode* root) {
        //��ÿһ���ڵ�ѡ�������߲�����ѡȡ�������
        int res = dp(root);
        return res;
    }
    int dp(TreeNode* root){
        if(root == NULL) return 0;
        if(memo.count(root) == 1) return memo[root];
        // �������������ڵĲ���
        int do_rob = root->val + (root->left == NULL?0:dp(root->left->left) + dp(root->left->right)) + (root->right==NULL?0:dp(root->right->left) + dp(root->right->right));
        // ��������������Ҫ��
        int not_rob = dp(root->left) + dp(root->right);
        int res = max(do_rob, not_rob);
        memo[root] = res;
        return res;

    }
};
