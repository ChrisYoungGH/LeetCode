class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch) {
    	++count[ch];
    	if (count[ch] == 1) {
    		data.push(ch);
    	}
    }

  //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
    	while (!data.empty() && count[data.front()] > 1) {
    		data.pop();
    	}
    	return data.empty() ? '#' : data.front();
    }

    Solution() {
    	memset(count, 0, sizeof(count));
    }

private:
	queue<int> data;
	int count[256];
};