class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        ds = self.string2index(s)
        dt = self.string2index(t)
        return ds == dt

    def string2index(self, s):
        strDict = {}
        count = 0
        ds = []
        for c in s:
            if c not in strDict:
                strDict[c] = count
                count += 1
            ds.append(strDict[c])
        return ds

    def isIsomorphic2(self, s, t):
        m1 = [0] * 256
        m2 = [0] * 256
        for i in range(len(s)):
            if (m1[ord(s[i])] != m2[ord(t[i])]):
                return False
            m1[ord(s[i])] = m2[ord(t[i])] = i + 1
        return True



if __name__ == '__main__':

    s = 'paper'
    t = 'title'
    print(Solution().isIsomorphic2(s, t))
