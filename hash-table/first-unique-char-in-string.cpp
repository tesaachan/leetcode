#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hashmap;
        for (int i = 0; i < s.size(); i++) {
            if (hashmap.count(s[i])) {
                hashmap[s[i]] += 1;
            } else {
                hashmap[s[i]] = 1;
            }
        } 
        for (int i = 0; i < s.size(); i++) {
            if (hashmap[s[i]] == 1)
                return i;
        }
        return -1;
    }
};