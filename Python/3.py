#!/usr/bin/env python
# encoding: utf-8

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s: return 0
        m = {}
        l = r = res = 0
        for i, c in enumerate(s):
            r = i
            if c in m:
                if  r - l > res: res = r - l
                if l < m[c] + 1: l = m[c] + 1
            m[c] = i

        return max(res,  r - l + 1)
