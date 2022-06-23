// always check border values, e.g. 0, 1, 9, 99, 999 ...
#include <unordered_set>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int form_number(int n) {
        if (n == 0)
            return 0;
        return pow(n % 10, 2) + form_number(n / 10);
    }
    bool isHappy(int n) {
        unordered_set<int> hashset;
        int num = n;
        while (true) {
            num = form_number(num);
            if (num == 1)
                return true;
            if (hashset.count(num))
                return false;
            hashset.insert(num);
        }
    }
};