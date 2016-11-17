class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g=sorted(g)
        s=sorted(s)
        # print(g)
        # print(s)
        j=0
        c=0
        for i,x in enumerate(g):
            # print(i,x)
            while(j<len(s)):
                if(x>s[j]):
                    j=j+1
                else:
                    break
            if(j>=len(s)):
                i=i-1
                break
            if(x>s[j]):
                break
            j=j+1
        return i+1
a=Solution()
b=a.findContentChildren([1,1,1], [1,0])
print(b)
