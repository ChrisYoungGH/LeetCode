class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        counts = {}
        for i in range(len(list1)):
            counts[list1[i]] = i

        ans = []
        minIndex = len(list1) + len(list2)
        for i in range(len(list2)):
            v = list2[i]
            if v not in counts:
                continue
            sumIndex = counts[v] + i
            if sumIndex < minIndex:
                minIndex = sumIndex
                ans = []
                ans.append(v)
            elif sumIndex == minIndex:
                ans.append(v)

        return ans

if __name__ == '__main__':
    list1 = ["Shogun","Tapioca Express","Burger King","KFC"]
    list2 = ["KFC","Shogun","Burger King"]
    print Solution().findRestaurant(list1, list2)
