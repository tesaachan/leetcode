#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (j < nums.size() && nums[j] % 2 == 0) {
                j++;
            }
            if (nums[i] % 2 == 0 && i > j) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        return nums;
    }
};