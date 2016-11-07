class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        f=0
        p=1
        l=len(s)
        if l==0:
            return 0
        d={s[0]:0}
        max=1
        while p<l:
            if s[p] in d:
                if d[s[p]]>=f:
                    f=d[s[p]]+1
            if max<p-f+1:
                max=p-f+1
            d[s[p]]=p
            p+=1
        return max              