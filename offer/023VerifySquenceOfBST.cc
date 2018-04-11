class Solution {
public:
	bool VerifySquenceOfBST(vector<int> &sequence) {
		return sequence.size() && verify(sequence, 0, int(sequence.size())-1);
	}

	bool verify(vector<int> &sequence, int begin, int end) {
		if (begin >= end) {
			return true;
		}

		int root = sequence[end];
		int rightBeginIndex = end;
		for (int i = begin; i < end; i++) {
			if (sequence[i] > root) {
				rightBeginIndex = i;
				break;
			}
		}

		for (int i = rightBeginIndex + 1; i < end; i++) {
			if (sequence[i] <= root) {
				return false;
			}
		}

		return verify(sequence, begin, rightBeginIndex-1) && verify(sequence, rightBeginIndex, end-1);
	}
};