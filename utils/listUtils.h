#ifndef LIST_UTILS_H
#define LIST_UTILS_H

#include <cstdlib>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(int *arr, int n);
ListNode* createList(vector<int> &arr);
ListNode *createList(int n, int bound, int random_state=0, bool sorted=true);

void displayList(ListNode *head);

void destroyList(ListNode *head);

#endif