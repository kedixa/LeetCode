/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    using Node = RandomListNode;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node*, Node*> um;
        um[nullptr] = nullptr; // 空指针映射为空指针
        Node *h = head, *nh = nullptr; // 头指针和新的头指针
        Node **p = &nh; // 指向最后一个结点next的指针
        while(h != nullptr)
        {
            *p = new Node(h -> label);
            um[h] = *p;
            p = &((*p)-> next);
            h = h -> next;
        }
        *p = nullptr;
        Node *result = nh; // 保存新的头指针，下面使用h, nh进行第二遍遍历恢复random指针
        for(h = head; h != nullptr; h = h -> next, nh = nh -> next)
            nh -> random = um[h->random];
        return result;
    }
};
