class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        letterCount = {}
        for c in magazine:
            letterCount[c] = letterCount.get(c, 0) + 1

        for c in ransomNote:
            if c not in letterCount or letterCount[c] <= 0:
                return False
            letterCount[c] = letterCount.get(c, 0) - 1

        return True
