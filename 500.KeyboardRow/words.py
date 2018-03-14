class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        a = set('qwertyuiop')
        b = set('asdfghjkl')
        c = set('zxcvbnm')

        ans = []

        for word in words:
            wset = set(word.lower())
            if wset & a == wset or \
                wset & b == wset or \
                wset & c == wset:
                ans.append(word)

        return ans
