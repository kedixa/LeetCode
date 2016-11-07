class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        p=0
        for i,num in enumerate(nums):
            if (num!=0):
                nums[p]=nums[i]
                p+=1
        if p<=len(nums)-1:
            nums[p:]=[0 for i in range(len(nums)-p)]
        return nums
