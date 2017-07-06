/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode *t = head;
        while(t) ++len, t = t->next;
        if(len < 2) return true;
        t = head;
        int k = 1;
        while(k < (len+1)/2) t = t->next, ++k;
        
        // 翻转后半段
        ListNode *h = nullptr, *p = t->next, *q;
        while(p) {
            q = p->next;
            p->next = h;
            h = p;
            p = q;
        }
        t->next = h; // 接上，链表别断了
        // 对比前半段和翻转的后半段
        while(h) {
            if(h->val != head->val) return false;
            h = h->next;
            head = head->next;
        }
        return true;
    }
};
