#include <iostream>
#include <random>
#include "quick_sort.h"

int main() {
    // 生成随机数引擎和分布器
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 999);

    // 生成随机数组
    const int n = 100;
    int A[n];
    for (int & i : A) {
        i = dis(gen); // 使用随机数引擎和分布器生成随机数
    }

    // 输出原始序列
    std::cout << "原始序列: ";
    for (int i : A) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // 对数组进行快速排序
    QuickSort(A, 0, n - 1);

    // 输出排序后序列
    std::cout << "排序后序列: ";
    for (int i : A) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}