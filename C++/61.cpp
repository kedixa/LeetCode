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
    ListNode* rotateRight(ListNode* head, int k) {
        /*
            先练成一个环，找到倒数第k个元素，从它之前将环拆开即可。
        */
        if(head == NULL) return head;
        ListNode* p = head;
        int sz = 1;
        while(p -> next != NULL) sz++, p = p -> next;
        p -> next = head; // 连成环
        k = (sz - k % sz) % sz; // 倒数变正数
        while(k--) p = p -> next;
        head = p -> next;
        p -> next = NULL;
        return head;
    }
};