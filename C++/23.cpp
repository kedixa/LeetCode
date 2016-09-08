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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        /*
            使用优先队列维护所有链表头部元素，
            每次取最小值加入到归并链表，
            复杂度O(n*m log nm)，n为链表个数，m为每个链表长度
        */
        int sz = lists.size();
        using intListNode = pair<int, ListNode*>;
        priority_queue<intListNode, std::vector<intListNode>, greater<intListNode>> que;
        ListNode *head = NULL, **phead = &head;
        for(auto& p : lists)
            if(p != NULL) que.push(make_pair(p->val, p));
        while(!que.empty())
        {
            auto q = que.top();
            que.pop();
            *phead = new ListNode(q.first);
            phead = &((*phead) -> next);
            auto next = q.second -> next;
            if(next != NULL) que.push(make_pair(next -> val, next));
        }
        return head;
    }
};