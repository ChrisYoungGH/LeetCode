class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        if not s:
            return s

        charArray = list(s)

        end = len(s) / (k*2) * (k*2)

        for i in range(0, end, k * 2):
            charArray[i:i+k] = charArray[i+k-1:(i-1 if i>0 else None):-1]

        i = end
        end = len(s) if (len(s) - end) < k else i + k
        charArray[i:end] = charArray[end-1:(i-1 if i>0 else None):-1]

        return ''.join(charArray)
