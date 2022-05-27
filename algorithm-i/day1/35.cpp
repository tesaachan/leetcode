#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = -1;
        int r = nums.size();
        while (r - l > 1) {
            int m = (r + l)/2;
            if (nums[m] == target)
                return m;
            if (nums[m] < target)
                l = m;
            else
                r = m;
        }
        return r;
    }
};