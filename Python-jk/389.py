class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        # a^a=0
        a=0
        for c in s:
            a=a^ord(c)
        for c in t:
            a=a^ord(c)
        return chr(a)