#include <stdio.h>
#include <vector>
using namespace std;

class Solution {
public:
    void setString(vector<char>& s, int i) {
        if (i >= s.size() / 2)
            return;
        swap(s[i], s[s.size() - 1 - i]);
        setString(s, i + 1);
    }
    void reverseString(vector<char>& s) {
        setString(s, 0);
    }
};

int main() {
    Solution a;
    vector<char> s {'h','e','l','l','o'};
    a.reverseString(s);
    for (int i = 0; i < s.size(); i++)
        printf("%c", s[i]);
}