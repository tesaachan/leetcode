#include "vector"
#include "cmath"
#include "iostream"
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int middle = 0;
        while (middle < n && nums[middle] < 0) {
            middle++;
        }
        for (int i = 0; i < n; i++) {
            nums[i] = pow(nums[i], 2);
        }
        vector<int> ans(n);

        int i = 0;
        int j = 0;
        while (middle - 1 - i >= 0 && j + middle < n)
        {
            if (nums[middle - 1 - i] < nums[j + middle]) {
                ans[i + j] = nums[middle - 1 - i];
                i++;
            } else {
                ans[i + j] = nums[j + middle];
                j++;
            }
        }
        while (middle - 1 - i >= 0)
        {
            ans[i + j] = nums[middle - 1 - i];
            i++;
        }
        while (j + middle < n)
        {
            ans[i + j] = nums[j + middle];
            j++;
        }
        return ans;
    }
};