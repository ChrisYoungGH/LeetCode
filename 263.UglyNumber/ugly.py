class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
        	return False
        if num == 1:
        	return True
    	while num > 1 and num % 2 == 0:
    		num /= 2
    	while num > 1 and num % 3 == 0:
    		num /= 3
    	while num > 1 and num % 5 == 0:
    		num /= 5
        if num > 1:
        	return False
        return True