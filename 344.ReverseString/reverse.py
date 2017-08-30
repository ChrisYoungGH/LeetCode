class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        array = list(s)
        for i in range(len(array) / 2):
            tmp = array[i]
            array[i] = array[len(array) - i - 1]
            array[len(s) - i - 1] = tmp
        return ''.join(array)

if __name__ == '__main__':
    print Solution().reverseString('hello')
