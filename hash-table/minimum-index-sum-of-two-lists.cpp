#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashmap;
        for (int i = 0; i < list1.size(); i++) {
            hashmap[list1[i]] = i;
        }
        vector<string> answer;
        int min_index_sum = 2001;
        for (int i = 0; i < list2.size(); i++) {
            if (hashmap.count(list2[i])) {
                int index_sum = hashmap[list2[i]] + i;
                if (index_sum < min_index_sum) {
                    min_index_sum = index_sum;
                    answer = {list2[i]};
                }
                else if (index_sum == min_index_sum) {
                    answer.push_back(list2[i]);
                }
            }
        }
        return answer;
    }
};