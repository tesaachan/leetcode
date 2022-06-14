// O(log k)
#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> indexes;
    void search(int k) {
        // cout << "k : " << k << endl;
        indexes.push_back(k % 2);
        if (k == 1)
            return;
        search(ceil((double)k / 2));
    }
    int kthGrammar(int n, int k) {
        search(k);
        reverse(indexes.begin(), indexes.end());
        vector<int> elems = {0, 1};
        for (int i = 0; i < indexes.size() - 1; i++) {
            // cout << indexes[i] << endl;
            if (indexes[i] == 1) {
                if (elems[0] == 0 && elems[1] == 1) elems = {0, 1};
                else elems = {1, 0};
            }
            else if (elems[0] == 0 && elems[1] == 1) elems = {1, 0};
            else elems = {0, 1};
        }
        if (indexes[indexes.size() - 1] == 1) return elems[0];
        else return elems[1];
    }
};

int main() {
    Solution a;
    int x = a.kthGrammar(5, 8);
    cout << "ans : " << x << endl;
}