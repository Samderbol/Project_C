#include <iostream>
#include <algorithm>
using namespace std;

int setPartition(int a[], int n) {
    int pivotkey, low = 0, low0 = 0, high = n - 1, high0 = n - 1, flag = 1, k = n / 2, i; //pivotkey保存枢轴元素值
    //low0,high0保存low,high的初值，避免丢失进行后续多轮的划分的位置定位
    int s1 = 0, s2 = 0; //记录A1、A2集合各自的和
    while(flag) {
        pivotkey = a[low]; //选择枢轴
        while(low < high) { //基于枢轴对数据进行划分
            while(low < high && a[high] >= pivotkey) --high; //若数组最右边的值比枢轴的值大，说明不需要调整，往左移动high继续比较即可
            if(low != high) a[low] = a[high]; //找到第一个比枢轴元素值小的元素，将其调整到前面
            while(low < high && a[low] <= pivotkey) ++low; //若数组最左边的值比枢轴的值小，说明不需要调整，往右移动low继续比较即可
            if(low != high) a[high] = a[low]; //找到第一个比枢轴元素值大的元素，将其调整到后面
        } //end of while(low < high)
        a[low] = pivotkey; //最后将枢轴放到两堆元素的中间
        if(low == k - 1) //如果枢轴是第n/2小元素，划分成功
            flag = 0;
        else{ //否则继续划分
            if(low < k - 1) { //枢轴及之前的元素均属于A1，继续对 low 之后的元素进行划分；
                low0 = ++low;
                high = high0;
            }
            else{ //否则枢轴及之后的元素均属于A2，继续对 low 之前的元素进行划分；
                high0 = --high;
                low = low0;
            }
        }
    }
    for(i = 0; i < k; i++) s1 += a[i]; //计算S1和
    for(i = k; i < n; i++) s2 += a[i]; //计算S2
    printf("%d %d", (n-k)-k, s2-s1);
    return s2-s1;
}


int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i < n; i++)
        cin>>a[i];
    setPartition(a,n);
}
