class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        ia = len(a) - 1
        ib = len(b) - 1
        carry = 0
        res = ""
        while ia > 0 or ib > 0 or carry:
            va = 0
            vb = 0
            if ia >= 0:
                va = int(a[ia])
            if ib >= 0:
                vb = int(b[ib])

            sum = va + vb + carry
            res += str(sum % 2)
            carry = sum / 2

            ia -= 1
            ib -= 1

        return res[::-1]

if __name__ == '__main__':
    print Solution().addBinary("11", "1")
