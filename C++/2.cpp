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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = NULL; // 结果的头指针
        ListNode **p = &l3; // 指向（指向链表最后一个元素的下一个元素的指针）的指针，便于构建链表
        int carry = 0; // 进位
        while(l1!=NULL || l2!=NULL)
        {
            // 如果两个链表都到达尾部则跳出循环
            if(l1==NULL && l2==NULL) break;

            // 计算本位（和上一位的进位）的和
            int s = carry;
            if(l1) s += l1->val, l1 = l1->next;
            if(l2) s += l2->val, l2 = l2->next;

            // 为结果建立新的结点，并计算进位
            *p = new ListNode(s%10);
            carry = s/10;

            // 移动指针到下一个位置
            p = &((*p)->next);
        }
        // 如果还有进位，则还需再建立一个结点
        if(carry != 0)
            *p = new ListNode(carry);
        return l3;
    }
};
