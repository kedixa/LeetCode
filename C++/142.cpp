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
    ListNode *detectCycle(ListNode *head) {
        // 使用两个指针，一个每次走一步，另一个每次走两步，如果不能相遇返回nullptr
        // 如果相遇了，第一个移回head，两个指针分别每次走一步，
        // 二者相遇的地方就是环开始的地方。
        // 记环开始的位置为p，指针相遇的位置为q，head 到p的距离为a，
        // p到q的距离为b，环的长度为c
        // 已知第一个指针走的长度为a+b, 第二个指针走a+b+c，
        // 第二个指针走的路程为第一个指针的二倍，可得c=a+b（c可能是圆周的整数倍，但没有关系）
        // 此时第二个指针距离p为c-b=a，head到p的距离也是a
        // 综上可得。
        if(head == nullptr || head -> next == nullptr) return nullptr;
        ListNode *p1 = head -> next, *p2 = head -> next -> next;
        if(p2 == nullptr) return nullptr;
        while(p1 != p2)
        {
            p1 = p1 -> next;
            p2 = p2 -> next;
            if(p2 == nullptr) return nullptr;
            p2 = p2 -> next;
            if(p2 == nullptr) return nullptr;
        }
        p1 = head;
        while(p1 != p2)
        {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return p1;
    }
};
