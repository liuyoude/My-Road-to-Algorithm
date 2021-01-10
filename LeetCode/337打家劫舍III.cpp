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
        //在每一个节点选择抢或者不抢，选取最大收益
        int res = dp(root);
        return res;
    }
    int dp(TreeNode* root){
        if(root == NULL) return 0;
        if(memo.count(root) == 1) return memo[root];
        // 抢，接下来相邻的不抢
        int do_rob = root->val + (root->left == NULL?0:dp(root->left->left) + dp(root->left->right)) + (root->right==NULL?0:dp(root->right->left) + dp(root->right->right));
        // 不抢，接下来的要抢
        int not_rob = dp(root->left) + dp(root->right);
        int res = max(do_rob, not_rob);
        memo[root] = res;
        return res;

    }
};
