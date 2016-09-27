# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    max=0
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # recuresive method
        self.max=1
        if root:
            self.traverseTree(root,1)
            return self.max
        else:
            return 0
    def traverseTree(self,root,n):
        if root.left:
            if n+1>self.max:
                self.max=n+1
            self.traverseTree(root.left,n+1)
        if root.right:
            if n+1>self.max:
                self.max=n+1
            self.traverseTree(root.right,n+1)
            