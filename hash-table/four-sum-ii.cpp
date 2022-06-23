#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hashset12;
        unordered_map<int, int> hashset34;

        for (int i = 0; i < nums1.size(); i++)
            for (int j = 0; j < nums2.size(); j++) {
                if (hashset12.count(nums1[i] + nums2[j]) == 0)
                    hashset12[nums1[i] + nums2[j]] = 0;
                hashset12[nums1[i] + nums2[j]]++;
            }
        for (int i = 0; i < nums3.size(); i++)
            for (int j = 0; j < nums4.size(); j++) {
                if (hashset34.count(nums3[i] + nums4[j]) == 0)
                    hashset34[nums3[i] + nums4[j]] = 0;
                hashset34[nums3[i] + nums4[j]]++;
            }
        int answer = 0;
        for (auto &it1 : hashset12) {
            for (auto &it2 : hashset34) {
                if (it1.first + it2.first == 0)
                    answer += it1.second * it2.second;
            }
        }
        return answer;
    }
};