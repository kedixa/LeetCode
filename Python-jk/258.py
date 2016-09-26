class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        res=num%9
        if res:
            return res
        elif num:
            return 9
        else:
            return 0