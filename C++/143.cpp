/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    void flip(ListNode **s)
    {
        // 翻转*s指向的链表
        if((*s)->next == nullptr) return;
        ListNode *head = *s;
        ListNode *p = head, *q = p -> next, *r;
        while(q != nullptr)
        {
            r = q->next;
            q -> next = head;
            p -> next = r;
            head = q;
            q = r;
        }
        *s = head;
    }
public:
    void reorderList(ListNode* head) {

        // 先计算链表的长度
        int length = 0;
        ListNode *p = head;
        while(p != nullptr)
        {
            ++length;
            p = p -> next;
        }
        if(length < 3) return;
        
        // 找到后半段链表，并翻转
        ListNode **q = &head;
        for(int i = 0; i < length/2 + 1; ++i)
            q = &((*q)->next);
        flip(q);
        
        // 依次从两个链表取一个元素，组成新的链表
        p = head;
        ListNode *r = *q; // last half head
        *q = nullptr; // break off
        while(r != nullptr)
        {
            ListNode *s = p -> next, *t = r -> next;
            p -> next = r, r -> next = s;
            p = s, r = t;
        }
    }
};
