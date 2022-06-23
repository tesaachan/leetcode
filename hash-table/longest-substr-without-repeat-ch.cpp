// brute-force solution. do it by sliding window
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lswrc = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> hashset;
            int swrc = 0;
            for (int j = i; j < s.size(); j++) {
                if (hashset.count(s[j]))
                    break;
                hashset.insert(s[j]);
                swrc++;
            }
            if (swrc > lswrc) lswrc = swrc;
        }
        return lswrc;
    }
};