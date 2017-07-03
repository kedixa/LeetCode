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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        // 每次从原链表前取出一个结点，并用头插法插入到新链表前面
        ListNode *p = nullptr, *q = nullptr;
        while(head) {
            p = head;
            head = head -> next;
            p -> next = q;
            q = p;
        }
        return q;
    }
};
