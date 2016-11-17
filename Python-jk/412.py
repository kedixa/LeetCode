class Solution(object):
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        l=[]
        for i in range(n):
            if (i+1)%3==0:
                if (i+1)%5==0:
                    l.append("FizzBuzz")
                else:
                    l.append("Fizz")
            elif (i+1)%5==0:
                l.append("Buzz")
            else:
                l.append(str(i+1))
        return l
