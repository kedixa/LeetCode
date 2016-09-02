#!/usr/bin/env python
# encoding: utf-8

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        '''
        遍历中心： 分左右奇偶
        '''
        l = len(s)
        left = 0 # 最左位置
        t = 1 # 总长度
        for i in xrange(l):
            j = 1 # 左右长度
            while i - j >= 0 and i + j < l:
                if s[i-j] != s [i+j]: break
                j += 1
            if j * 2 - 1 > t:
                t = j * 2 - 1
                left = i - j + 1
            j = 1
            while i - j + 1 >= 0 and i + j < l:
                if s[i-j+1] != s[i+j]: break
                j += 1
            if 2 * j - 2 > t:
                t = j * 2 - 2
                left = i - j + 2
        return s[left: left+t]
