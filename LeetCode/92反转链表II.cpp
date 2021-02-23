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
        // left=1时就是反转前right个节点
        if(left == 1){
            return reverseN(head, right);
        }
        // 反转head->next开始的前left-1到right-1个节点
        head->next = reverseBetween(head->next, left-1, right-1);
        return head;
    }

    // 反转前n个节点
    ListNode* reverseN(ListNode* head, int n){
        // n=1时，需要记录后置节点
        if(n == 1){
            backNext = head->next;
            return head;
        }
        if(head->next == nullptr) return head;
        // 反转前n-1个节点
        ListNode* last = reverseN(head->next, n-1);
        // 将前n-1节点的尾结点（head->next）的next指向head
        head->next->next = head;
        // head节点的next指向last节点的后置节点
        head->next = backNext;
        return last;
    }
};
