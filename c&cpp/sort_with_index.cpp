// DESCRIPTION: sort a list of variable with their index
// TAG: vector, sort
// STANDARD: c++11
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include "helper.h"
using namespace std;
vector<size_t> sort_with_index(vector<int>& array) {
    int n = array.size();
    vector<size_t> idxs(n, 0);
    iota(idxs.begin(), idxs.end(), 0); // a list of increasing number
    sort(idxs.begin(), idxs.end(), [&](size_t& a, size_t& b){ return array[a] < array[b]; });
    sort(array.begin(), array.end(), [](int& a, int& b){return a < b;});
    return idxs;
}
void test_sort_with_index() {
    vector<int> arr = {1, 5, 2, 3, 6, 2, 7, 8};
    vector<size_t> idxs = sort_with_index(arr);
    print_vector(idxs);
    printf("\n");
    print_vector(arr);
    printf("\n");
}
int main() {
    test_sort_with_index();
    return 0;
}