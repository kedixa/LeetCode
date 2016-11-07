class Solution(object):
    def countBattleships(self, board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        count=0
        last=False
        for i,row in enumerate(board):
            last=False
            for j,c in enumerate(row):
                if c=='X':
                    if last==False:
                        count=count+1
                    last=True
                else:
                    last=False
        tboard=map(list, zip(*board))
        for i,row in enumerate(tboard):
            last=False
            for j,c in enumerate(row):
                if c=='X':
                    if last==True:
                        count=count-1
                    last=True
                else:
                    last=False
        return count

# board=[
# 'X..X',
# 'X...',
# 'X.XX']
# a=Solution()
# b=a.countBattleships(board)
# print(b)
