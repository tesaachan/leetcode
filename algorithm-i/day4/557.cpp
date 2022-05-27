#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (j == s.size()-1 || s[j+1] == ' ')
            {
                for (int k = 0; k < (j - i)/2 + 1; k++) {
                    swap(s[i+k], s[j-k]);
                }
                i = j + 2;
            }
        }
        return s;
    }
};