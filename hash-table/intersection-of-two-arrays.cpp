#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashset;
        vector<int> answer;
        for (int i = 0; i < nums1.size(); i++) {
            hashset.insert(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (hashset.count(nums2[i])) 
            {
                hashset.erase(nums2[i]);
                answer.push_back(nums2[i]);
            }
        }
        return answer;
    }
};