#ifndef __HELPER_H
#define __HELPER_H
#include <iostream>
#include <vector>
template<typename T>
void print_vector(std::vector<T> arr) {
    for(auto item: arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
#endif // __HELPER_H