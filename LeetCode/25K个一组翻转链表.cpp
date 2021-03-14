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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *a, *b;
        a = head; 
        b = head;
        for(int i = 0; i < k; i ++){
            // ����k������ԭλ��
            if(b == nullptr) return head;
            b = b->next;
        }
        // ��ת�ڵ�[a,b)
        ListNode* newHead = reverse(a, b);
        // �ݹ鷴ת[b, ...]������ǰһ��ڵ��β�����ӵ��������ڵ��ͷ��
        a->next = reverseKGroup(b, k);
        return newHead;

    }

    ListNode* reverse(ListNode* a, ListNode* b){
        ListNode *pre, *cur, *nxt;
        pre = nullptr; cur = a; nxt = a;
        while(cur != b){
            // ��¼��ǰ�ڵ���һ���ڵ�
            nxt = cur->next;
            // ��ת��ǰ�ڵ�
            cur->next = pre;
            // ָ��ǰ��
            pre = cur;
            cur = nxt;
            
        }
        return pre;
    }
};
