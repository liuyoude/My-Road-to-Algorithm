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
    ListNode* backNext = nullptr;
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // left=1ʱ���Ƿ�תǰright���ڵ�
        if(left == 1){
            return reverseN(head, right);
        }
        // ��תhead->next��ʼ��ǰleft-1��right-1���ڵ�
        head->next = reverseBetween(head->next, left-1, right-1);
        return head;
    }

    // ��תǰn���ڵ�
    ListNode* reverseN(ListNode* head, int n){
        // n=1ʱ����Ҫ��¼���ýڵ�
        if(n == 1){
            backNext = head->next;
            return head;
        }
        if(head->next == nullptr) return head;
        // ��תǰn-1���ڵ�
        ListNode* last = reverseN(head->next, n-1);
        // ��ǰn-1�ڵ��β��㣨head->next����nextָ��head
        head->next->next = head;
        // head�ڵ��nextָ��last�ڵ�ĺ��ýڵ�
        head->next = backNext;
        return last;
    }
};
