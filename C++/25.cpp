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
    ListNode* reverseKGroup(ListNode* head, int k) {
        /*
            定义：Only constant memory是指占用空间与链表长度和k都无关，实际上用递归来偷鸡也不成。
            这是一个有意思的题，不使用调试器通过这道题，你的指针水平就可以入门了
            使用二级指针指向（指向剩余链表的第一个元素的指针）
        */
        ListNode **phead = &head;
        while(true)
        {
            int tmp = k;
            ListNode *p = *phead;
            /*
            首先查看是否还有k个元素，
            */
            while(p != NULL && --tmp) p = p -> next;
            /*
            元素不够则直接退出
            */
            if(p == NULL) break;
            /*
            此时 *phead指向第一个元素，p指向第k个元素，
            初始化pre为指向第k+1个元素的指针，next为指向第一个元素的指针
            */
            ListNode *pre = p -> next, *next = *phead;
            /*
            该循环可以画一张图来演示
            */
            while(pre != p)
            {
                /*
                next指向的(元素的next指针)指向pre指向的元素
                */
                ListNode *tmp = next;
                next = next -> next;
                tmp -> next = pre;
                pre = tmp;
            }
            /*
            修改该k-Group的头指针至下一个Group
            */
            ListNode **pnext = &((*phead) -> next);
            *phead = p;
            phead = pnext;
        }
        return head;
    }
};