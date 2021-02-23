/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        connectTwoNode(root->left, root->right);
        return root;
    }

    void connectTwoNode(Node* left, Node* right){
        if(left == NULL) return;
        left->next = right;
        // ����һ���ڵ�����ҽڵ�
        connectTwoNode(left->left, left->right);
        connectTwoNode(right->left, right->right);
        // ���������ڵ�֮��Ľڵ�
        connectTwoNode(left->right, right->left);
    }
};
