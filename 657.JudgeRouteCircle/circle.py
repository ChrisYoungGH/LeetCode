class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        count = dict.fromkeys(list('UDLR'), 0)
        for c in moves:
            count[c] += 1
        if count['U'] == count['D'] and count['L'] == count['R']:
            return True
        return False
