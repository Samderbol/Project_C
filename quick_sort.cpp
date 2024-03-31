#include "quick_sort.h"

int Partition(int A[], int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot) {
            --high;
        }
        A[low] = A[high];
        //从数组末尾向前移动指针 high，直到找到一个小于基准元素的值或者 high 指针与 low 指针相遇
        while (low < high && A[low] <= pivot) {
            ++low;
        }
        A[high] = A[low];
        //从数组起始位置向后移动指针 low，直到找到一个大于基准元素的值或者 low 指针与 high 指针相遇
    }
    A[low] = pivot;
    return low;
}
//返回基准元素的索引，以便后续对左右子数组进行递归排序
void QuickSort(int A[], int low, int high) {
    if (low < high) {
        int pivot = Partition(A, low, high);
        QuickSort(A, low, pivot - 1);  //对基准元素右侧的子数组进行递归排序
        QuickSort(A, pivot + 1, high);  //对基准元素右侧的子数组进行递归排序
    }
}