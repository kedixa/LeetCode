class Solution(object):
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        sum=0
        count=0
        l=len(A)
        if l<=2:
            return 0
        s1=A[0:l-1]
        s2=A[1:l]
        s=s2[0]-s1[0]-1
        for i in range(l-1):
            t=s2[i]-s1[i]
            if s==t:
                count=count+1
            else:
                if count>0:
                    sum=sum+count*(count+1)/2
                count=0
            s=t
        if count>0:
            sum=sum+count*(count+1)/2
        return int(sum)
