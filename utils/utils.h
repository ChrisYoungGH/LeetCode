#ifndef UTILS_H
#define UTILS_H

#include <vector>

using namespace std;

void random_init_i(int *arr, int n, int bound, int random_state=0, bool sorted=true);
void random_init_i(vector<int> &arr, int n, int bound, int random_state=0, bool sorted=true);
void random_init_i(vector<int> &arr, int bound, int random_state=0, bool sorted=true);

void random_init_d(double *arr, int n, int bound, int random_state=0, bool sorted=true);
void random_init_d(vector<double> &arr, int n, int bound, int random_state=0, bool sorted=true);
void random_init_d(vector<double> &arr, int bound, int random_state=0, bool sorted=true);

#endif