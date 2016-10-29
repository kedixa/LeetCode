#!/usr/bin/env python
# encoding: utf-8

'''
94%
'''
class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        '''
        s = min(a[i], a[j]) * (j -i)
        从首尾两侧开始滑动
        if a[l] > a[r]: 那么可能最大的在r 的左侧
        if a[l] > a[r]: 那么可能最大的在 l的右边
        '''
        res = 0
        l = 0
        r = len(height) - 1
        while l < r:
            area = (r - l) * min(height[l], height[r])
            if res < area: res = area
            if height[l] < height[r]: l += 1
            elif height[l] > height[r]: r -= 1
            else: l += 1
        return res
