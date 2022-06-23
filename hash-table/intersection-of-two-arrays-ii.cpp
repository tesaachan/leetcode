#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums1.size(); i++) {
            if (hashmap.count(nums1[i]))
                hashmap[nums1[i]]++;
            else
                hashmap[nums1[i]] = 1;
        }
        vector<int> answer;
        for (int i = 0; i < nums2.size(); i++) {
            if (hashmap[nums2[i]]) {
                answer.push_back(nums2[i]);
                hashmap[nums2[i]]--;
            }
        }
        return answer;
    }
};