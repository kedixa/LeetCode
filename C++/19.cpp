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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
            先将一个指针first移动到第n个位置,
            再同时移动last和first,
            当first到达链表末尾的时候,last恰好为倒数第n个元素
        */
        ListNode *first = head, **last = &head;
        while(--n) first = first -> next;
        while(first -> next != NULL) first = first -> next, last = &((*last) -> next);
        first = (*last);
        *last = first -> next;
        delete first;
        return head;
    }
};