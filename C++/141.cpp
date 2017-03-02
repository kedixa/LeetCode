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
    bool hasCycle(ListNode *head) {
        // 使用两个指针，p1每次走一步，p2每次走两步，如果有环，它们必定会相遇
        if(head == nullptr) return false;
        ListNode *p1 = head, *p2 = head -> next;
        if(p2 == nullptr) return false;
        while(p1 != p2)
        {
            p1 = p1 -> next;
            p2 = p2 -> next;
            if(p2 == nullptr) return false;
            p2 = p2 -> next;
            if(p2 == nullptr) return false;
        }
        return true;
    }
};
