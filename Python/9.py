#!/usr/bin/env python
# encoding: utf-8

'''
beats 99.28%
'''
class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0: return False
        t = x
        y = 0
        '''
        从右往左形成新数字
        '''
        while t > 9:
            y = (y + t % 10) * 10
            t /=10

        return y + t == x

