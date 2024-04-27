#include <iostream>
#include <unordered_set>
using namespace std;

// 链表节点定义
struct ListNode {
    int data;
    ListNode* next;
    explicit ListNode(int x) : data(x), next(nullptr) {}  //禁止隐式类型转换
};

ListNode* removeDuplicates(ListNode* head) {
    if (!head)
        return nullptr;

    ListNode* newHead = head;
    ListNode* prev = newHead;  //头插法建立链表
    ListNode* curr = head->next;  //移动当前指针

    while (curr) {
        // 检查新链表中是否已存在该元素的绝对值
        int absValue = abs(curr->data);
        bool duplicate = false; //检查重复性
        ListNode* temp = newHead;
        while (temp != curr) {
            if (abs(temp->data) == absValue) {
                duplicate = true;
                break;
            }
            temp = temp->next;
        }

        // 如果新链表中不存在该元素的绝对值，则将其插入新链表
        if (!duplicate) {
            prev->next = curr;  //如果该元素的的重复性不存在，则输出
            prev = curr;    //
        }

        curr = curr->next;   //移动新链表的curr指针
    }

    // 将新链表的末尾置空
    prev->next = nullptr;

    return newHead;
}

// 输出链表
void printList(ListNode* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl; //输出结尾的空指针
}

// 释放链表内存
void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    // 构建链表
    auto head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(-2);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(4);

    cout << "原始链表：" << endl;
    printList(head);

    // 调用函数去除重复节点
    ListNode* newHead = removeDuplicates(head);

    cout << "去除重复节点后的链表：" << endl;
    printList(newHead);

    // 释放链表内存
    deleteList(newHead);

    return 0;
}
