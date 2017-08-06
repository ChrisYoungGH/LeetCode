#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

/**
 * vector, map, unordered_map的初始化例子
 */

void test_map() {
    map<int,int> m = {
        {5,2000},
        {2,3000},
        {3,4000},
        {4,7000}
    };

    for (map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << ":" << it->second << " ";
    }
    cout << endl;
}

void test_unordered_map() {
    unordered_map<int,int> m = {
        {5,2000},
        {2,3000},
        {3,4000},
        {4,7000}
    };

    for (unordered_map<int,int>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << ":" << it->second << " ";
    }
    cout << endl;
}

void test_vector() {
    vector<int> v = {1,2,3,4,5};
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    test_map();
    test_unordered_map();
    test_vector();
    return 0;
}
