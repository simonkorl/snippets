#include <iostream>
#include <vector>
#include <helper.h>
using namespace std;
void qsort(int l, int r, vector<int>& arr) {
    if(l >= r) return;
    swap(arr[l], arr[(l + r) / 2]);
    int i = l, j = r - 1, pivot = arr[l];
    while(i < j) {
        while(i < j && arr[j] > pivot) j--;
        if(i < j) arr[i++] = arr[j];
        while(i < j && arr[i] < pivot) i++;
        if(i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;
    qsort(l, i - 1, arr);
    qsort(i + 1, r, arr);
}
int main() {
    vector<int> array = {2,5,1,1,6,1,6,8,7,2,7,2,6,2,1};
    print_vector(array);
    qsort(0, array.size(), array);
    print_vector(array);
    return 0;
}