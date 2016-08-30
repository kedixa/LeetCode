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
        ListNode *l3 = NULL; // �����ͷָ��
        ListNode **p = &l3; // ָ��ָ���������һ��Ԫ�ص���һ��Ԫ�ص�ָ�룩��ָ�룬���ڹ�������
        int carry = 0; // ��λ
        while(l1!=NULL || l2!=NULL)
        {
            // ���������������β��������ѭ��
            if(l1==NULL && l2==NULL) break;

            // ���㱾λ������һλ�Ľ�λ���ĺ�
            int s = carry;
            if(l1) s += l1->val, l1 = l1->next;
            if(l2) s += l2->val, l2 = l2->next;

            // Ϊ��������µĽ�㣬�������λ
            *p = new ListNode(s%10);
            carry = s/10;

            // �ƶ�ָ�뵽��һ��λ��
            p = &((*p)->next);
        }
        // ������н�λ�������ٽ���һ�����
        if(carry != 0)
            *p = new ListNode(carry);
        return l3;
    }
};
