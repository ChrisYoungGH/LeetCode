class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
            
        characters = {}
        for c in s:
            characters[c] = characters.get(c, 0) + 1

        for c in t:
            if c not in characters or characters[c] == 0:
                return False
            else:
                characters[c] -= 1

        return True
