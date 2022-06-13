#include "stdio.h"
#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
    node *prev;
    node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class MyLinkedList {
private:
    node *head = nullptr;
    node *tail = nullptr;
public:
    int size;

    int get(int index) {
        if (index >= size || index < 0)
            return -1;
        else {
            node *ptr = nullptr;
            if (size / 2 - index > 0) {
                ptr = head;
                while (index) {
                    ptr = ptr->next;
                    index--;
                }
            } else {
                ptr = tail;
                while (index < size - 1) {
                    ptr = ptr->prev;
                    index++;
                }
            }
            return ptr->val;
        }
    }
    void addAtHead(int val) {
        if (head == nullptr) {
            head = new node(val);
            tail = head;
        } else {
            node *ptr = new node(val);
            head->prev = ptr;
            ptr->next = head;
            ptr->prev = nullptr;
            head = ptr;
        }
        size++;
    }
    void addAtTail(int val) {
        if (tail == nullptr) {
            tail = new node(val);
            head = tail;
        }
        node *ptr = new node(val);
        tail->next = ptr;
        ptr->prev = tail;
        ptr->next = nullptr;
        tail = ptr;
        size++;
    }
    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        if (index == size) 
            return addAtTail(val);
        if (index == 0)
            return addAtHead(val);
        
        node *ptr = nullptr;
        if (size / 2 - index > 0) {
            ptr = head;
            while (index) {
                ptr = ptr->next;
                index--;
            }
        } else {
            ptr = tail;
            while (index < size - 1) {
                ptr = ptr->prev;
                index++;
            }
        }
        node *added = new node(val);
        added->next = ptr;
        added->prev = ptr->prev;
        ptr->prev->next = added;
        ptr->prev = added;
        size++;
    }
    void deleteAtIndex(int index) {
        if (index >= size || index < 0)
            return;
        if (index == 0) {
            if (size == 1) {
                head = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
        }
        else if (index == size - 1) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            node *ptr = nullptr;
            if (size / 2 - index > 0) {
                ptr = head;
                while (index) {
                    ptr = ptr->next;
                    index--;
                }
            } else {
                ptr = tail;
                while (index < size - 1) {
                    ptr = ptr->prev;
                    index++;
                }
            }
            node *ptrprev = ptr->prev;
            node *ptrnext = ptr->next;
            ptrnext->prev = ptrprev;
            ptrprev->next = ptrnext;
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

void printList(MyLinkedList *mll) {
    for (int i = 0; i < mll->size; i++) {
        cout << mll->get(i) << ' ';
    }
    cout << endl;
}

int main() {
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtHead(1);
    printList(&myLinkedList);
    myLinkedList.addAtTail(3);
    printList(&myLinkedList);
    myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
    printList(&myLinkedList);
    myLinkedList.get(1);              // return 2
    myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
    printList(&myLinkedList);
    myLinkedList.get(1);              // return 3

    // MyLinkedList myLinkedList = MyLinkedList();
    // myLinkedList.addAtHead(1);
    // printList(&myLinkedList);
    // myLinkedList.deleteAtIndex(0);
    // printList(&myLinkedList);
}
