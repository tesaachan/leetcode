#include "stdio.h"
#include <iostream>
using namespace std;

struct node {
    int val;
    node *next;
    node(int val) {
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList {
private:
    int     size;
    node    *head;
public:
    MyLinkedList() {
        size = 0;
        head = NULL;
    }
    
    int get(int index) {
        if (size <= index) {
            return -1;
        }
        node *tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        return tmp->val;
    }
    
    void addAtHead(int val) {
        node *tmp = new node(val);
        tmp->next = head;
        head = tmp;
        size++;
    }
    
    void addAtTail(int val) {
        if (size == 0) {
            head = new node(val);
        } else {
            node *tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = new node(val);
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (size < index) {
            return;
        }
        if (index == 0) {
            node *tmp = new node(val);
            tmp->next = head;
            head = tmp;
        } else {
            node *prev = head;
            node *next = head->next;
            for (int i = 0; i < index - 1; i++) {
                prev = prev->next;
                next = next->next;
            }
            prev->next = new node(val);
            prev->next->next = next;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (size <= index) {
            return;
        }
        if (index == 0) {
            node *tmp = head;
            head = head->next;
            delete tmp;
        } else {
            node *prev = head;
            node *next = head->next;
            for (int i = 0; i < index - 1; i++) {
                prev = prev->next;
                next = next->next;
            }
            if (next != NULL) {
                prev->next = next->next;
                delete next;
            } else {
                prev->next = NULL;
            }
        }
        size--;
    }
};

void show(node *head) {
    while (head != NULL) {
        cout << head->val << ' ';
        head = head->next;
    }
    cout << endl;
}

int main()
{
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtIndex(0, 10);
    myLinkedList.addAtHead(2);
    myLinkedList.addAtHead(1);
    cout << myLinkedList.get(1) << endl;
    myLinkedList.deleteAtIndex(0);
    cout << myLinkedList.get(0) << endl;
    myLinkedList.addAtIndex(3, 0);
    myLinkedList.addAtHead(6);
    myLinkedList.addAtTail(4);
}
