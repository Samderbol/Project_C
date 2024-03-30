#include <iostream>
#include "quick_sort.h"

int main() {
    int A[] = {5, 2, 9, 3, 7, 6, 8, 1, 4};
    int n = sizeof(A) / sizeof(A[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    QuickSort(A, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
