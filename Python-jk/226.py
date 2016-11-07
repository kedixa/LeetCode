# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root:
            self.traverseTree(root)
        return root
    def traverseTree(self,root):
        if root.left:
            if root.right:
                tmp=root.right
                root.right=root.left
                root.left=tmp
                self.traverseTree(root.left)
                self.traverseTree(root.right)
            else:
                root.right=root.left
                root.left=None
                self.traverseTree(root.right)
        elif root.right:
            root.left=root.right
            root.right=None
            self.traverseTree(root.left)
            