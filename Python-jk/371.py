class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        while (a&b)<<1:  
            temp=a  
            a=a^b  
            b=(temp&b)<<1
        return a^b
        