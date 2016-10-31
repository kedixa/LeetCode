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
    ListNode* partition(ListNode* head, int x) {
        /*
         * p1指向第一不小于x的结点，p2向后找小于x的结点，将这个结点移除并插入到p1的位置。
        */
        ListNode **p1 = &head;
        while(*p1 && (*p1) -> val < x) p1 = &((*p1) -> next);
        if(*p1 == NULL) return head;
        ListNode **p2 = &((*p1) -> next);
        while(*p2)
        {
            if((*p2) -> val < x)
            {
                // 这块要细腻
                ListNode *p = *p2;
                *p2 = p -> next;
                p -> next = (*p1);
                *p1 = p;
                p1 = &(p -> next);
            }
            else p2 = &((*p2) -> next);
        }
        return head;
    }
};