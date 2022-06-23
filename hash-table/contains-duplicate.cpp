#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (auto &num : nums) {
            if (hashset.count(num) == 1)
                return true;
            hashset.insert(num);
        }
        return false;
    }
};