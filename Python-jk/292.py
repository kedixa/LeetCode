class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return bool(n%4)
        """
        if n%4:
            return True
        else:
            return False
        """