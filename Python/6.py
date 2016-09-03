#!/usr/bin/env python
# encoding: utf-8

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        '''
        一行一行构造- 使用列表提高效率
        '''
        n = numRows
        if n == 1: return s
        r = []
        l = len(s)
        for i in range(n):
            j = i
            while j < l:
                r.append(s[j])
                if 0 < j+2*n-2-2*i < l and j%(n-1): r.append(s[j+2*n-2-2*i])
                j += 2 * n - 2
        return ''.join(r)

