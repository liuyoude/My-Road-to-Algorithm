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
解法1：利用递归得到链表的逆序遍历 
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
        // 逆序遍历链表，right从右向左，left从左向右
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
解法2： 快慢链表找中点，反转中点后半段链表
*/ 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 利用快慢指针找中点
        ListNode *slow, *fast;
        slow = head; fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        //链表长为奇数时slow还需指向next
        if(fast != nullptr) slow = slow->next;

        // 反转slow后面的链表
        ListNode* left = head;
        ListNode* right = reverse(slow);

        // 从终端对比原指针和翻转指针
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
