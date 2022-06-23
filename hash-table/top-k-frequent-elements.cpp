#include <unordered_set>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> topk;
        for (int i = 0; i < nums.size(); i++) {
            if (freq.count(nums[i]) == 0)
                freq[nums[i]] = 0;
            freq[nums[i]]++;
        }
        for (auto &it : freq) {
            topk[it.second].push_back(it.first);
        }
        vector<int> answer;
        for (int i = nums.size(); i != 0; i--) {
            if (k == 0)
                break;
            int j = 0;
            while (topk.count(i) && j < topk[i].size()) {
                answer.push_back(topk[i][j]);
                j++;
                k--;
            }
        }
        return answer;
    }
};