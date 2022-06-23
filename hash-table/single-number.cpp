#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashset;
        for (auto &num : nums) {
            if (hashset.count(num) == 0) {
                hashset.insert(num);
            } else {
                hashset.erase(num);
            }
        }
        for (auto &num : nums) {
            if (hashset.count(num) == 1)
                return num;
        }
    }
};