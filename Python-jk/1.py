class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        s={} # s is an empty dict 
        for i,num in enumerate(nums): # enumerate() can return the index and element
            if (target-num) in s:
                return [s[target-num],i] 
            s[num]=i
        