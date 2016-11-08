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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // 若只有一个结点则不交换
        if(n == m) return head; 
        ListNode **p = &head;
        int t = 1;
        // 首先找到第一个需要交换的结点的位置m
        while(t++ < m) p = &((*p) -> next);
        // 使用三个指针依次将结点的next指针回指，其中结点m暂不回指
        ListNode *q = *p, *r = q -> next, *s;
        while(t++ <= n)
        {
            s = r -> next;
            r -> next = q;
            q = r;
            r = s;
        }
        (*p) -> next = r; // 修复m结点的next指针
        (*p) = q; // 修复指向m结点的指针为反转后的起始结点
        return head;
    }
};