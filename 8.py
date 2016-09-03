#!/usr/bin/env python
# encoding: utf-8

class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        '''
        基本使用内置: 居然超过了100%...可能判断机制做了修改
        '''
        s=re.search(r'^([+-]?\d+)',str.strip())
        if not s:
            return 0
        res = int(s.group(1))
        if res>0 and abs(res) > 2147483647:
            return 2147483647
        if res<0 and abs(res)> 2147483648:
            return -2147483648
        return res
