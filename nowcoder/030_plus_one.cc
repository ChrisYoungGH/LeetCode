class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        int n = digits.size();
        for (int i = n-1; i >= 0; i--) {
        	int sum = digits[i] + carry;
        	digits[i] = sum % 10;
        	carry = sum / 10;
        }
        if (carry) {
        	digits.push(carry, 0);
        }

        return digits;
    }
};