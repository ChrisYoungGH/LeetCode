#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "utils.h"

using namespace std;

// randomly initialize an integer array
void random_init_i(int *arr, int n, int bound, int random_state, bool sorted) {
	if (random_state) {
		srand(time(NULL) + random_state);
	}

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % bound;
	}

	if (sorted) {
		sort(arr, arr+n);
	}
}

// randomly initialize an integer vector
void random_init_i(vector<int> &arr, int n, int bound, int random_state, bool sorted) {
	if (random_state) {
		srand(time(NULL) + random_state);
	}
	
	for (int i = 0; i < n; i++) {
		arr.push_back(rand() % bound);
	}

	if (sorted) {
		sort(arr.begin(), arr.end());
	}
}

// randomly initialize an integer vector
void random_init_i(vector<int> &arr, int bound, int random_state, bool sorted) {
	if (random_state) {
		srand(time(NULL) + random_state);
	}

	int n = arr.size();
	
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % bound;
	}

	if (sorted) {
		sort(arr.begin(), arr.end());
	}
}

// randomly initialize an double array
void random_init_d(double *arr, int n, int bound, int random_state, bool sorted) {
	if (random_state) {
		srand(time(NULL) + random_state);
	}
	
	for (int i = 0; i < n; i++) {
		arr[i] = double(rand()) / RAND_MAX;
	}

	if (sorted) {
		sort(arr, arr+n);
	}
}

// randomly initialize an double vector
void random_init_d(vector<double> &arr, int n, int bound, int random_state, bool sorted) {
	if (random_state) {
		srand(time(NULL) + random_state);
	}
	
	for (int i = 0; i < n; i++) {
		arr.push_back(double(rand()) / RAND_MAX);
	}

	if (sorted) {
		sort(arr.begin(), arr.end());
	}
}

// randomly initialize an double vector
void random_init_d(vector<double> &arr, int bound, int random_state, bool sorted) {
	if (random_state) {
		srand(time(NULL) + random_state);
	}

	int n = arr.size();
	
	for (int i = 0; i < n; i++) {
		arr[i] = double(rand()) / RAND_MAX;
	}

	if (sorted) {
		sort(arr.begin(), arr.end());
	}
}