class Solution(object):
    def checkRecord(self, s):
        """
        :type s: str
        :rtype: bool
        """
        countA = 0
        countL = 0
        for c in s:
            if c == 'L':
                countL += 1
            else:
                countL = 0
                if c == 'A':
                    countA += 1

            if countA > 1 or countL > 2:
                return False
        return True
