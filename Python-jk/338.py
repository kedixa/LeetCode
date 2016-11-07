import math

class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        if num==0:
            return [0]
        if num==1:
            return [0,1]
        bits=[0,1]
        r=math.ceil(math.log(num+1,2))
        for i in range((int)(r-1)):
            l=len(bits)
            for j in range(l):
                bits.append(bits[j]+1)
        return bits[0:num+1:1]
