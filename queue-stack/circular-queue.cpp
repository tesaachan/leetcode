#include <vector>
using namespace std;

class MyCircularQueue {
public:
    vector<int> Queue;
    int tail;
    int head;

    MyCircularQueue(int k) {
        Queue.resize(k);
        tail = -1;
        head = -1;
    }
    
    bool enQueue(int value) {
        if (this->isFull())
            return false;
        if (this->isEmpty()) {
            head = 0;
            tail = head;
            Queue[head] = value;
        } else {
            tail = (tail + 1) % Queue.size();
            Queue[tail] = value;
        }
        return true;
    }
    
    bool deQueue() {
        if (this->isEmpty())
            return false;
        if (head == tail) {
            head = -1;
            tail = -1;
        } else {
            head = (head + 1) % Queue.size();
        }
        return true;
    }
    
    int Front() {
        if (this->isEmpty())
            return -1;
        return Queue[head];
    }
    
    int Rear() {
        if (this->isEmpty())
            return -1;
        return Queue[tail];
    }
    
    bool isEmpty() {
        return (head == -1);
    }
    
    bool isFull() {
        return (tail + 1) % Queue.size() == head;
    }
};

void print_queue(MyCircularQueue *q) {
    cout << "head: " << q->head << endl;
    cout << "tail: " << q->tail << endl;
    for (int i=0;i<q.size();i++) {
        cout << "[" << q[i] << "]";
    }
    cout << endl;
}

int main() {
    MyCircularQueue* obj = new MyCircularQueue(k);
    bool param_1 = obj->enQueue(value);
    print_queue(obj);
    bool param_2 = obj->deQueue();
    print_queue(obj);
    int param_3 = obj->Front();
    print_queue(obj);
    int param_4 = obj->Rear();
    print_queue(obj);
    bool param_5 = obj->isEmpty();
    bool param_6 = obj->isFull();
}