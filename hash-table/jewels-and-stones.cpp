#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> hashset;
        for (auto &c : jewels)
            hashset.insert(c);
        int ans = 0;
        for (auto &c : stones)
            if (hashset.count(c)) ans++;
        return ans;
    }
};