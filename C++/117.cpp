/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // 暂时还不会O(1)空间的做法
        // 使用广度优先遍历，对每层的结点添加连接即可
        if(root == NULL) return;
        queue<TreeLinkNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int sz = que.size();
            TreeLinkNode *p = que.front();
            que.pop();
            for(int i = 1; i < sz; i++)
            {
                if(p->left) que.push(p->left);
                if(p->right) que.push(p->right);
                p->next = que.front();
                p = que.front();
                que.pop();
            }
            if(p->left) que.push(p->left);
            if(p->right) que.push(p->right);
            p = NULL;
        }
    }
};
