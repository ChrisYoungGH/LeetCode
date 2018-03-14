class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = dict.fromkeys(list('aeiouAEIOU'))
        index = []
        for i in range(len(s)):
            if s[i] in vowels:
                index.append(i)

        ans = list(s)
        for i in range(len(index) / 2):
            tmp = ans[index[i]]
            ans[index[i]] = ans[index[len(index)-i-1]]
            ans[index[len(index)-i-1]] = tmp

        return ''.join(ans)

if __name__ == '__main__':
    s = 'hello'
    print Solution().reverseVowels(s)
