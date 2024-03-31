#include <iostream>

void cmpCountSort(int a[], int b[], int n) {
    int* count = new int[n]; // 分配动态数组以存储计数
    for (int i = 0; i < n; i++) // 初始化计数数组
        count[i] = 0;

    // 计算每个元素的计数
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] < a[j]) {
                count[j]++;
            } else {
                count[i]++;
            }
        }
    }

    // 根据计数数组排序元素
    for (int i = 0; i < n; i++) {
        b[count[i]] = a[i];
    }

    delete[] count; // 释放动态数组内存
}

int main() {
    int a[] = {5, 2, 9, 3, 7, 6, 8, 1, 4};
    int n = sizeof(a) / sizeof(a[0]);
    int b[n]; // 用于存储排序后的数组

    cmpCountSort(a, b, n);

    std::cout << "原始序列: ";
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "排序后序列: ";
    for (int i = 0; i < n; ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
