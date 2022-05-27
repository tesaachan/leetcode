#include "vector"
#include "iostream"
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int j = 1;
        int max = arr[1];
        for (int i = 2; i < arr.size(); i++)
        {
            if (arr[i] > max) {
                max = arr[i];
                j = i;
            }
        }
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (i < j) {
                arr[i] = max;
            } else {
                max = arr[i + 1]; 
                for (int k = i + 2; k < arr.size(); k++)
                {
                    if (arr[k] > max) {
                        max = arr[k];
                        j = k;
                    }
                }
                arr[i] = max;
            }
        }
        arr[arr.size() - 1] = -1;
    }
};
