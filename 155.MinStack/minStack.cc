#include <vector>
#include <cstdio>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        data.push_back(x);
        if (mins.size() == 0) {
            mins.push_back(x);
        }
        else {
            int t = mins.back();
            mins.push_back(min(t, x));
        }
    }
    
    void pop() {
        if (data.size() > 0) {
            data.resize(int(data.size())-1);
            mins.resize(int(mins.size())-1);
        }
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return mins.back();
    }

private:
    vector<int> data;
    vector<int> mins;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main() {
    // MinStack s = MinStack();

    // int arr[] = {7,8,3,2,4,1,6,5};
    // int n = sizeof(arr) / sizeof(int);
    // for (int i = 0; i < n; i++) {
    //     s.push(arr[i]);
    // }
    // printf("top: %d\n", s.top());
    // s.pop();
    // printf("top: %d\n", s.top());
    // printf("min: %d\n", s.getMin());

    MinStack s = MinStack();
    s.push(2147483646);
    s.push(2147483646);
    s.push(2147483647);
    s.pop();
    s.pop();
    s.pop();
    s.push(2147483647);
    s.top();
    s.getMin();
    s.push(-2147483648);
    s.top();
    s.getMin();
    s.pop();
    s.getMin();

    return 0;
}


