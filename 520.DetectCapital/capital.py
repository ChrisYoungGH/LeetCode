class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        if word.isupper() or word.islower() or word[1:].islower():
            return True
        return False

if __name__ == '__main__':
    s = 'USAn'
    print Solution().detectCapitalUse(s)
