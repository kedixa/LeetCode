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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sa = 0, sb = 0;
        // 先计算两个链表的长度
        ListNode *p = headA;
        while(p) ++sa, p = p->next;
        p = headB;
        while(p) ++sb, p = p->next;
        // 将两个链表对齐
        if(sa < sb)
            while(sa != sb) headB = headB->next, --sb;
        else if(sa > sb)
            while(sa != sb) headA = headA->next, --sa;
        // 从对齐的位置开始找，必然在相交的位置相遇
        while(headA != headB) headA = headA->next, headB = headB->next;
        return headA;
    }
};
