/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
�ⷨ1�����õݹ�õ������������� 
*/ 
class Solution {
public:
    ListNode* left;
    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);

    }
    bool traverse(ListNode* right){
        if(right == nullptr) return true;
        bool res = traverse(right->next);
        // �����������right��������left��������
        res = res && (left->val == right->val);
        left = left->next;
        return res;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
/*
�ⷨ2�� �����������е㣬��ת�е��������
*/ 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // ���ÿ���ָ�����е�
        ListNode *slow, *fast;
        slow = head; fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        //����Ϊ����ʱslow����ָ��next
        if(fast != nullptr) slow = slow->next;

        // ��תslow���������
        ListNode* left = head;
        ListNode* right = reverse(slow);

        // ���ն˶Ա�ԭָ��ͷ�תָ��
        while(right != nullptr){
            if(left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;

    }

    ListNode* reverse(ListNode* head){
        ListNode *pre, *cur;
        pre = nullptr;
        cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
