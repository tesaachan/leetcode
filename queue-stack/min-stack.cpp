#include <vector>
using namespace std;

class MinStack {
private:
    vector<int> stack;
    int minElem;
public:
    MinStack() {}
    
    void push(int val) {
        stack.push_back(val);
        if (stack.size() == 1 || val < minElem)
            minElem = val;
        stack.push_back(minElem);
    }
    
    void pop() {
        stack.pop_back();
        stack.pop_back();
        if (stack.size() > 0)
            minElem = stack.back();
    }
    
    int top() {
        int elem = stack.back();
        stack.pop_back();
        int ans = stack.back();
        stack.push_back(elem);
        return ans;
    }
    
    int getMin() {
        return stack.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */