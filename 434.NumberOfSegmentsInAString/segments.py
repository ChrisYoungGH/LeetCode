class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        flag = 0
        count = 0
        for c in s:
            if not c.isspace():
                flag = 1
            else:
                if flag == 1:
                    count += 1
                flag = 0

        return count + (flag == 1)

if __name__ == '__main__':
    s = 'Hello, my name is John. '
    print Solution().countSegments(s)
