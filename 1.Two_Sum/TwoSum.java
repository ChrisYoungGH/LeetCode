import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Arrays;

public class TwoSum {

	public int[] twoSum(int[] nums, int target) {
		if (nums.length <= 1) {
			return null;
		}

		// 将nums的值和下标存在map里
		// 考虑存在重复的情况，每个key对应的值为一个list，
		// 存该数值对应的所有下标
		Map<Integer, List<Integer>> numMap = new HashMap<>();
		int currIdx = 0;
		for (int n : nums) {
			Integer key = Integer.valueOf(n);
			if (!numMap.containsKey(key)) {
				numMap.put(key, new ArrayList<Integer>());
			}
			numMap.get(key).add(currIdx++);
		}

		// 遍历nums的数值，用target减去，寻找差值是否在map中
		int[] result = new int[2];
		int firstIdx = 0, secondIdx = 0;
		for (Entry<Integer, List<Integer>> entry : numMap.entrySet()) {
			Integer first = entry.getKey();
			List<Integer> firstIndices = entry.getValue();
			Integer remain = Integer.valueOf(target) - first;
			if (numMap.containsKey(remain)) {
				// 如果在map中，判断是否与原数相同
				if (remain.equals(first)) {
					// 如果相同，则下标list的长度不能为1，否则是同一个下标
					if (firstIndices.size() == 1) {
						continue;
					}
					firstIdx = firstIndices.get(0);
					secondIdx = firstIndices.get(1);
				}
				// 如不相同，则各取下标list的第一个
				else {
					List<Integer> secondIndices = numMap.get(remain);
					firstIdx = firstIndices.get(0);
					secondIdx = secondIndices.get(0);
				}

				// 排序，保证返回的下表是升序的
				if (firstIdx > secondIdx) {
					int temp = firstIdx;
					firstIdx = secondIdx;
					secondIdx = temp;
				}

				result[0] = firstIdx;
				result[1] = secondIdx;
			}
		}

		return result;
	}


	// 优化方法：遍历nums数值，如果值不在map中，则加入target减去它的差值；
	// 否则则是找到，返回
	// 方法可以达到线性
    public int[] twoSumOptimal(int[] nums, int target) {
 		if (nums.length <= 1) {
 			return null;
 		}
 		Map<Integer, Integer> numMap = new HashMap<Integer, Integer>();
 		for (int i = 0; i < nums.length; i++) {
 			if (numMap.containsKey(nums[i])) {
 				return new int[] {numMap.get(nums[i]), i};
 			}
 			else {
 				numMap.put(target - nums[i], i);
 			}
 		}
 		return null;
    }


    public static void main(String[] args) {
    	int[] nums = new int[]{2, 7, 11, 15};
    	int target = 9;
    	System.out.println(Arrays.toString(new TwoSum().twoSum(nums, target)));
    }
}
