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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*
            比较两个链表第一个元素,将较小的那个放到归并链表,并将原链表的指针后移;
        */
        ListNode *head = NULL;
        ListNode ** p = &head;
        int val;
        while(l1 && l2)
        {
            if(l1 -> val < l2 -> val) val= l1 -> val, l1 = l1 -> next;
            else val= l2 -> val, l2 = l2 -> next;
            *p = new ListNode(val);
            p = &((*p) -> next);
        }
        /*
            如果一个链表为空,则另一个链表依次放到归并链表后
        */
        if(l1 == NULL) l1 = l2;
        while(l1) *p = new ListNode(l1 -> val), p = &((*p) -> next), l1 = l1 -> next;
        return head;
    }
};