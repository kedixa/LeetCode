class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=0
        for i in nums:
            res^=i
        return i
        # d={}
        # for num in nums:
        #     if num in d:
        #         d[num]=2
        #     else:
        #         d[num]=1
        # for num in d:
        #     if d[num]==1:
        #         return num
        