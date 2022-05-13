// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int firstBadVersion(int n) {
        ll left = 0;
        ll right = n;
        while (right - left > 1) {
            ll m = (right + left) / 2;
            if (isBadVersion(m))
                right = m;
            else
                left = m;
        }
        return right;
    }
};