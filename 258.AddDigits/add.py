class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        while num >= 10:
        	tmp = num
        	num = 0
        	while tmp:
        		num += tmp % 10
        		tmp /= 10
        return num

    def addDigits(self, num):
    	return 1 + (num - 1) % 9