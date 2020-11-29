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
        // ���ö��д�Žڵ�
        queue<TreeNode*> q;
        q.push(root);
        int step = 1;
        // ���зǿ�ʱѭ��
        while(! q.empty()){
            int sz = q.size();
            // ��ɢ��ǰ��ڵ�
            for(int i=0; i < sz; i ++ ){
                TreeNode* cur = q.front();
                q.pop();
                // left��right�ڵ��ΪnullptrʱΪҶ�ӽڵ�
                if(cur->left == nullptr && cur->right == nullptr){
                    return step;
                }
                // ������Χ�ڵ�
                if(cur->left != nullptr) q.push(cur->left);
                if(cur->right != nullptr) q.push(cur->right);
            }
            // ���²���
            step ++;
        }
        return step;
    }
};
