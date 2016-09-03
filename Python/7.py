#!/usr/bin/env python
# encoding: utf-8

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        t=x
        if x<0:
            x=-x
        x=int(str(x)[::-1])
        return 0 if x>=1<<31 else x if t>0 else -x

