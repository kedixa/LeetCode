# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        val = 0
        p = head
        while True:
            if l1 is None and l2 is None: break
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            p.next = ListNode(val % 10)
            val /= 10
            p = p.next
        if val > 0:
            p.next = ListNode(val)
        return head.next

'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} l1
    # @param {ListNode} l2
    # @return {ListNode}
    def addTwoNumbers(self, l1, l2):
        def conver(l):
            li = []
            while l:
                li.append(l.val)
                l=l.next
            return int(''.join(map(str,li[::-1])))

        li1 = conver(l1)
        li2 = conver(l2)
        res = str(li1+li2)[::-1]
        head = ListNode(res[0])
        p=head
        if len(res) ==1:
            return head
        for i in range(len(res)-1):
                q = ListNode(res[i+1])
                p.next=q
                p=q

        return head
'''
