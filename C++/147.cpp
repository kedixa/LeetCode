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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return head;
        int lastval = head->val;
        ListNode **p = &(head->next);
        while(*p != nullptr)
        {
            if((*p)->val < lastval)
            {
                ListNode *q = *p;
                *p = (*p)->next;
                if(head->val >= q->val)
                {
                    q->next = head;
                    head = q;
                }
                else
                {
                    ListNode *r = head;
                    while(r->next->val < q->val) r = r->next;
                    q->next = r->next;
                    r->next = q;
                }
            }
            else
            {
                lastval = (*p)->val;
                p = &((*p)->next);
            }
        }
        return head;
    }
};
