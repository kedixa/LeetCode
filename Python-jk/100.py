# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        self.r=True
        if p:
            if q:
                self.traverseTree(p,q)
            else:
                self.r=False
        else:
            if q:
                self.r=False
        return self.r
    def traverseTree(self,p,q):
        if p.val==q.val:
            if p.left:
                if q.left:
                    self.traverseTree(p.left,q.left)
                else:
                    self.r=False
            else:
                if q.left:
                    self.r=False
            if p.right:
                if q.right:
                    self.traverseTree(p.right,q.right)
                else:
                    self.r=False
            else:
                if q.right:
                    self.r=False
        else:
            self.r=False