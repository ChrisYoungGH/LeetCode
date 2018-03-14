class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if not s:
            return True

        alphebetical = list('qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789')

        s_filter = [c.lower() for c in s if c in alphebetical]

        for i in range(len(s_filter)):
            if s_filter[i] != s_filter[len(s_filter)-i-1]:
                return False
        return True

if __name__ == '__main__':
    s = 'A man, a plan, a canal: Panama'
    print Solution().isPalindrome(s)
