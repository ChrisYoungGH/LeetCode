#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

	vector<int> twoSum(vector<int> &nums, int target) {
		vector<int> result;

		if (nums.size() <= 1) {
			return result;
		}

		// 将nums的值和下标存在map里
		// 考虑存在重复的情况，每个key对应的值为一个list，
		// 存该数值对应的所有下标
		map<int, vector<int> > numMap;
		int currIdx = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			map<int, vector<int> >::iterator hit = numMap.find(*it);
			if (hit == numMap.end()) {
				numMap[*it] = *(new vector<int>);
			}
			vector<int> *indicesList = &(numMap[*it]);
			indicesList->push_back(currIdx++);
		}

		// 遍历nums的数值，用target减去，寻找差值是否在map中
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
			vector<int> firstIndices = numMap[*it];
			int remain = target - (*it);
			map<int, vector<int> >::iterator hit = numMap.find(remain);
			int firstIdx, secondIdx;
			if (hit != numMap.end()) {
				// 如果在map中，判断是否与原数相同
				if (remain == (*it)) {
					// 如果相同，则下标list的长度不能为1，否则是同一个下标
					if (firstIndices.size() == 1) {
						continue;
					}
					firstIdx = firstIndices[0];
					secondIdx = firstIndices[1];
				}
				// 如不相同，则各取下标list的第一个
				else {
					vector<int> secondIndices = numMap[remain];
					firstIdx = firstIndices[0];
					secondIdx = secondIndices[0];
				}

				// 排序，保证返回的下表是升序的
				if (firstIdx > secondIdx) {
					int temp = firstIdx;
					firstIdx = secondIdx;
					secondIdx = temp;
				}

				result.push_back(firstIdx);
				result.push_back(secondIdx);

				break;
			}
		}

		return result;
	}


	// 优化方法：遍历nums数值，如果值不在map中，则加入target减去它的差值；
	// 否则则是找到，返回
	// 方法可以达到线性
	vector<int> twoSumOptimal(vector<int> &nums, int target) {
		vector<int> result;

		if (nums.size() <= 1) {
			return result;
		}

		map<int, int> numMap;
		for (int i = 0; i < nums.size(); i++) {
			map<int, int>::iterator it = numMap.find(nums[i]);
			if (it != numMap.end()) {
				result.push_back(it->second);
				result.push_back(i);
				break;
			}
			else {
				numMap[target - nums[i]] = i;
			}
		}

		return result;
	}
};

int main() {
	int numsArr[] = {2, 7, 11, 15};
	vector<int> nums(numsArr, numsArr + 4);
	int target = 9;

	Solution s = Solution();
	vector<int> result = s.twoSum(nums, target);
	for (vector<int>::iterator it = result.begin(); it != result.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}
