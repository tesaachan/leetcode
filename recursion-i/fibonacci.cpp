#include <map>
using namespace std;

class Solution {
public:
    map<int, int> fibonacci;
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        if (fibonacci.find(n) != fibonacci.end())
            return fibonacci[n];
        fibonacci[n] = fib(n - 1) + fib(n - 2);
        return fibonacci[n];
    }
};