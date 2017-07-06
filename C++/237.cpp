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
    void deleteNode(ListNode* node) {
        // 将该点后面的值往前移动即可（题目要求的delete无法实现）
        if(node->next == nullptr) return;
        while(true) {
            node->val = node->next->val;
            if(node->next->next == nullptr) break;
            node = node->next;
        }
        delete node->next;
        node->next = nullptr;
    }
};
