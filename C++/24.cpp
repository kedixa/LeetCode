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
    ListNode* swapPairs(ListNode* head) {
        /*
            二级指针便于操作
        */
        ListNode **phead = &head;
        while(*phead != NULL)
        {
            /*
            定义指向两个被交换结点的指针，若最后只有一个结点，则不交换
            */
            ListNode *p1 = *phead, *p2 = p1 -> next;
            if(p2 == NULL) break;
            /*
            交换结点的部分
            */
            p1 -> next = p2 -> next;
            p2 -> next = p1;
            *phead = p2;
            phead = &(p1 -> next);
        }
        return head;
    }
};