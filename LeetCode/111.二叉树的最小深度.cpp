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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        // 设置队列存放节点
        queue<TreeNode*> q;
        q.push(root);
        int step = 1;
        // 队列非空时循环
        while(! q.empty()){
            int sz = q.size();
            // 扩散当前层节点
            for(int i=0; i < sz; i ++ ){
                TreeNode* cur = q.front();
                q.pop();
                // left和right节点均为nullptr时为叶子节点
                if(cur->left == nullptr && cur->right == nullptr){
                    return step;
                }
                // 加入周围节点
                if(cur->left != nullptr) q.push(cur->left);
                if(cur->right != nullptr) q.push(cur->right);
            }
            // 更新层数
            step ++;
        }
        return step;
    }
};
