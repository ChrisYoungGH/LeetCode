class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split(' ')
        words = [self.reverse(word) for word in words]
        return ' '.join(words)

    def reverse(self, s):
        return s[::-1]

if __name__ == '__main__':
    s = "Let's take LeetCode contest"
    print Solution().reverseWords(s)
