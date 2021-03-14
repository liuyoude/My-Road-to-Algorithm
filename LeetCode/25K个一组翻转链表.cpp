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
            // 不足k个保持原位置
            if(b == nullptr) return head;
            b = b->next;
        }
        // 反转节点[a,b)
        ListNode* newHead = reverse(a, b);
        // 递归反转[b, ...]，并将前一组节点的尾部连接到接下来节点的头部
        a->next = reverseKGroup(b, k);
        return newHead;

    }

    ListNode* reverse(ListNode* a, ListNode* b){
        ListNode *pre, *cur, *nxt;
        pre = nullptr; cur = a; nxt = a;
        while(cur != b){
            // 记录当前节点下一个节点
            nxt = cur->next;
            // 反转当前节点
            cur->next = pre;
            // 指针前移
            pre = cur;
            cur = nxt;
            
        }
        return pre;
    }
};
