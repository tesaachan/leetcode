#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++) {
            if (hashmap.count(nums[i]))
                if (abs(hashmap[nums[i]] - i) <= k)
                    return true;
            hashmap[nums[i]] = i;
        }
        return false;
    }
};