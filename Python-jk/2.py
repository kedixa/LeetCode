# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import math
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        s=0
        head=ListNode(0)
        p=head
        while True:
            if l1 is None and l2 is None:
                break
            if l1:
                s+=l1.val
                l1=l1.next
            if l2:
                s+=l2.val
                l2=l2.next
            p.next=ListNode(s%10)
            p=p.next
            s/=10
        if s>=1:
            p.next=ListNode(s%10)
        return head.next