#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <windows.h>
#include "SortingAlgorithm.hpp"

int main(int argc, char **argv)
{
    if (argc == 1){ //if no arguments are given
        std::cerr << "Vectors length must be given as an argument" << std::endl;
        return 1;
    }
    for (unsigned int j = 1; j<argc; j++) {
        unsigned int s = 50;
        int n = atoi(argv[j]);
        std::vector<int> v_1(n);
        std::vector<int> v_2(n);
        v_1.resize(n);
        v_2.resize(n);
        std::cout << "Random generation of vector elements, length: " << n << std::endl;
        for(int i = 0; i<n; i++) {
            v_1[i] = rand() % 1000;
            v_2[i] = v_1[i];
        }

        double v1_average = 0;
        double v2_average = 0;
        for (unsigned int i = 0; i<s; i++) {
            std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
            SortLibrary::MergeSort(v_1);
            std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
            v1_average += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();
        }
        std::cout << "Merge sort time: " << v1_average/s << std::endl;

        for (unsigned int i = 0; i<s; i++) {
            std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();
            SortLibrary::BubbleSort(v_2);
            std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();
            v2_average += std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_begin).count();
        }
        std::cout << "Bubble sort time: " << v2_average/s << std::endl;
        std::cout << "-----" << std::endl;
    }
    std::cout << "    (time is given in microseconds)" << std::endl;
    std::cout << std::endl << "Press a key to close" << std::endl;
    std::getchar();

    return 0;
}

