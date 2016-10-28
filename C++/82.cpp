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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** p = &head; // 定义指向head的指针
        while(*p && (*p) -> next) // 若至少还有两个元素
        {
            int v = (*p) -> val;
            if((*p) -> next -> val == v) // 且两个元素相同
            {
                while((*p) != NULL && (*p) -> val == v) // 删除所有的值为v的结点
                {
                    ListNode *q = *p;
                    *p = (*p) -> next;
                    delete q;
                }
            }
            else p = &((*p) -> next); // 若两个元素不同，则指向下一个元素
        }
        return head;
    }
};