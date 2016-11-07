class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        d={}
        for c in magazine:
            if c in d:
                d[c]+=1
            else:
                d[c]=1
        for c in ransomNote:
            if c in d:
                if d[c]>0:
                    d[c]-=1
                else:
                    return False
            else:
                return False
        return True
