
class Solution(object):

	def twoSum(self, nums, target):
		
		# 将nums的值和下标存在字典里
		# 考虑存在重复的情况，每个key对应的值为一个list，
		# 存该数值对应的所有下标
		numDict = {}
		currIdx = 0
		for n in nums:
			if n not in numDict.keys():
				numDict[n] = []
			numDict[n].append(currIdx)
			currIdx += 1

		# 遍历nums的数值，用target减去，寻找差值是否在dict中
		result = []
		for first in numDict.keys():
			firstIndices = numDict[first]
			remain = target - first
			if remain in numDict.keys():
				# 如果在dict中，判断是否与原数相同
				if remain == first:
					# 如果相同，则下标list的长度不能为1，否则是同一个下标
					if len(firstIndices) == 1:
						continue
					firstIdx = firstIndices[0]
					secondIdx = firstIndices[1]
				# 如不相同，则各取下标list的第一个
				else:
					secondIndices = numDict[remain]
					firstIdx = firstIndices[0]
					secondIdx = secondIndices[0]

				# 排序，保证返回的下表是升序的
				if firstIdx > secondIdx:
					tmp = firstIdx
					firstIdx = secondIdx
					secondIdx = tmp

				result = [firstIdx, secondIdx]
				break

		return result


	# 优化方法：遍历nums数值，如果值不在dict中，则加入target减去它的差值；
	# 否则则是找到，返回
	# 方法可以达到线性
	def twoSumOptimal(self, nums, target):
		if len(nums) <= 1:
			return False

		numDict = {}
		for i in range(len(nums)):
			if nums[i] in numDict:
				return [numDict[nums[i]], i]
			else:
				numDict[target - nums[i]] = i



if __name__ == '__main__':
	nums = [2, 7, 11, 15]
	target = 9
	print Solution().twoSum(nums, target)
	print Solution().twoSumOptimal(nums, target)