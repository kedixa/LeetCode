# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    sum=0
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root:
            self.traverseTree(root,0)
        return self.sum
    def traverseTree(self,root,d):
        if root.left:
            self.traverseTree(root.left,1)
            if root.right:
                self.traverseTree(root.right,2)
        elif root.right:
            self.traverseTree(root.right,2)
        elif (d==1):
            self.sum+=root.val 