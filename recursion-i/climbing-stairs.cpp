#include <map>
using namespace std;

class Solution {
public:
    map<int, int> steps;
    int climbStairs(int n) {
        if (n == 1 || n == 2)
            return n;
        if (steps.find(n) != steps.end())
            return steps[n];
        steps[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return steps[n];
    }
};