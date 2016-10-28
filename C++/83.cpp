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
        ListNode *p1 = head, *p2 = head;
        if(!p2) return head;
        p2 = p2 -> next; // p2 向前走一步
        while(p2)
        {
            // 找到下一个不同的元素，记录到p1
            if(p2 -> val != p1 -> val)
            {
                p1 = p1 -> next;
                p1 -> val = p2 -> val;
            }
            p2 = p2 -> next;
        }
        // 删除p1后面的所有元素
        while(p1 -> next)
        {
            p2 = p1 -> next;
            p1 -> next = p2 -> next;
            delete p2;
        }
        return head;
    }
};