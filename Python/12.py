class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        '''
        1 5 10 50 100 500 1000
        I V X  L   C   D   M
        十进制的每一位单独处理即可。。。
        针对十进制，一位一位的计算即可。
        只有1,4,5,9 相对是特殊的。打表处理，
        '''
        res = ''
        a = [1000,900,500,400,100,90,50,40,10,9,5,4,1]
        b = ['M','CM', 'D','CD','C','XC', 'L','XL','X','IX', 'V', 'IV','I']
        for i,d in enumerate(a):
            if num >= d:
                res += num/d * b[i]
                num -= num/d*d
        return res
