class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        people.sort(key=lambda x:(x[0],-x[1]),reverse=True)
        # print(people)
        re_people=[]
        for i,x in enumerate(people):
            re_people.insert(x[1],x)
        # print(re_people)
        return re_people

a=Solution()
b=a.reconstructQueue([[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]])
print(b)
