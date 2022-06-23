#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashmap_s;
        unordered_map<char, char> hashmap_t;
        for (int i = 0; i < s.size(); i++) {
            if ((hashmap_s.count(s[i]) && hashmap_s[s[i]] != t[i])
                || (hashmap_t.count(t[i]) && hashmap_t[t[i]] != s[i]))
                return false;
            hashmap_s[s[i]] = t[i];
            hashmap_t[t[i]] = s[i];
        }
        return true;
    }
};