//
// Created by sam on 24-11-8.
//
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// 创建一个带头结点的单链表
Node* createList() {
    Node* head = new Node();
    head->next = nullptr;
    return head;
}

// 插入新节点到链表尾部
void insertNode(Node* head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 打印链表
void printList(Node* head) {
    Node* temp = head->next;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// 简单选择排序
void selectionSort(Node* head) {
    if (head == nullptr || head->next == nullptr) return;  // 链表为空或只有一个节点

    Node* cur = head->next;  // 当前节点
    while (cur != nullptr) {
        Node* minNode = cur;
        Node* nextNode = cur->next;

        // 在当前节点之后找最小元素
        while (nextNode != nullptr) {
            if (nextNode->data < minNode->data) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        // 如果找到的最小节点不等于当前节点，则交换数据
        if (minNode != cur) {
            swap(minNode->data, cur->data);
        }

        // 移动到下一个节点
        cur = cur->next;
    }
}

int main() {
    Node* list = createList();

    // 插入一些数据
    insertNode(list, 5);
    insertNode(list, 2);
    insertNode(list, 9);
    insertNode(list, 1);
    insertNode(list, 4);

    cout << "Before sorting: ";
    printList(list);

    // 对链表进行简单选择排序
    selectionSort(list);

    cout << "After sorting: ";
    printList(list);

    return 0;
}
