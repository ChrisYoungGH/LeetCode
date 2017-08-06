class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        up = 1
        for i in range(len(digits)-1, -1, -1):
            val = digits[i] + up
            digits[i] = val % 10
            up = val / 10

        if up:
            newDigits = [up]
            newDigits.extend(digits)
            return newDigits
        return digits

if __name__ == '__main__':
    print Solution().plusOne([9,9,9,9])
