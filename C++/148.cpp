/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
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
    // 排序函数的实现
    ListNode* sort_list_impl(ListNode *head, int sz)
    {
        // 对于小数据，使用朴素方法排序
        if(sz < 12) return insertionSortList(head);
        // 对于大数据，将数据分成两部分，分别排序，然后合并
        ListNode *h1 = head, *h2 = head;
        int half = sz / 2;
        while(--half) h2 = h2->next;
        half = sz / 2;  // 注意恢复
        ListNode *p = h2->next;
        h2->next = nullptr;  // 注意断开
        h1 = sort_list_impl(h1, half);
        h2 = sort_list_impl(p, sz - half);
        
        // 合并两个有序链表
        ListNode **q = &head;
        while(h1 != nullptr && h2 != nullptr)
        {
            if(h1->val > h2->val) swap(h1, h2);
            *q = h1;
            q = &(h1->next);
            h1 = h1->next;
        }
        if(h1 != nullptr) *q = h1;
        else *q = h2;
        return head;
    }
public:
    ListNode* sortList(ListNode* head) {
        // 先算出长度，便于使用分治法进行排序
        int sz = 0;
        ListNode *p = head;
        while(p != nullptr) p = p->next, ++sz;
        return sort_list_impl(head, sz);
    }
};
