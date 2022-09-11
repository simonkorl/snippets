// DESCIPTION: return the smallest sum of #k elements in the first #m elements in the array
// TAG: priority_queue, array
// LEETCODE: 823
#include <iostream>
#include <vector>
#include <queue>
#include "helper.h"
using namespace std;
vector<int> smallest_k_sum(vector<int>& array, int k) {
    int n = array.size();
    vector<int> res;
    if(n <= k) {
        for(int i = 0;i < n; ++i) {
            if(i == 0) {
                res[i] = array[0];
            } else {
                res[i] = array[i] + res[i - 1];
            }
        }
    }
    priority_queue<int, vector<int>, less<int>> heap;
    int sum = 0;
    for(int i = 0;i < k - 1; ++i) {
        sum += array[i];
        heap.push(array[i]);
        res.push_back(sum);
    }
    for(int i = k - 1;i < n; ++i) {
        sum += array[i];
        heap.push(array[i]);
        res.push_back(sum);
        sum -= heap.top();
        heap.pop();
    }
    return res;
}

void test_smallest_k_sum() {
    vector<int> arr = {223,235,661,161,22,574,136,41,472, 24, 2, 452, 24};
    print_vector(smallest_k_sum(arr, 5));
}
int main() {
    test_smallest_k_sum();
    return 0;
}