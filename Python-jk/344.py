class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        l=len(s)
        r=''
        for i in range(l):
            r+=s[l-i-1]
        return r
a=Solution()
b=a.reverseString('abd')
print(b)