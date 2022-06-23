#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        for (auto & s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end());
            if (hashmap.count(sorted_s))
                hashmap[sorted_s].push_back(s);
            else
                hashmap[sorted_s] = {s};
        }
        vector<vector<string>> answer;
        for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
            answer.push_back(it->second);
        }
        return answer;
    }
};