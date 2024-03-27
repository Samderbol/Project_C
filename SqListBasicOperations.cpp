#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define InitSize 10//默认的最大长度
using namespace std;
typedef struct {
    int* data;     //指示动态分配数组的指针
    int MaxSize;   //顺序表的最大容量
    int length;    //顺序表的当前长度
} SeqList;

void InitList(SeqList& L) {
    //用 malloc函数申请一片连续的存储空间
    L.data = (int*)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

bool ListInsert(SeqList& L, int i, int e) {
    if (i < 1 || i > L.MaxSize) {
        cout << "out of index before insert (length is: " << L.MaxSize << ")";
        return false;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    if (i < 1 || i > L.MaxSize) {
        cout << "out of index after insert (length is: " << L.MaxSize << ")";
        return false;
    }
    L.length++;
    if (L.length >= L.MaxSize) {
        cout << "out of index after insert (length is: " << L.MaxSize << ")";
        return false;
    }
    cout << L.length << endl;
    return true;
}

bool ListDelete(SeqList& L, int i, int& e) {
    if (i < 1 || i>L.length)
        return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
        L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

void IncreaseSize(SeqList& L, int len) {
    int* p = L.data;
    L.data = (int*)malloc((L.MaxSize + len) * sizeof(int));
    if (L.data == NULL) {
        // 可以处理内存分配失败的情况
        // 可以选择输出错误信息或采取其他适当的处理方式
        return;
    }
    if (len <= 0) {
        // 处理 len 为非正数的情况
        // 可以选择输出错误信息或采取其他适当的处理方式
        return;
    }
    for (int i = 0; i < L.length; i++) {
        L.data[i] = p[i];  //将数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len; //顺序表最大长度增加 len
    cout << L.MaxSize << endl;
    free(p);
}
int GetElem(SeqList L, int i) {
    return L.data[i - 1];
}
int LocateElem(SeqList L, int e) {
    for (int i = 0; i < L.length; i++)
        if (L.data[i] == e)
            return 0;
}

int main() {
    //声明一个顺序表
    SeqList L;
    //初始化顺序表
    InitList(L);
    //...往顺序表中随便插入几个元素...
    IncreaseSize(L, 5);
    bool insertResult = ListInsert(L, 5, 3);
    int e = -1;


    if (insertResult) {
        cout << "Insertion successful." << endl;
    }
    else {
        cout << "Insertion failed." << endl;
    }

    if (ListDelete(L, 1, e))
        printf("已删除第三个元素，删除元素值为=%d\n", e);
    else
        printf("位序不合法,删除失效\n");

    return 0;
}