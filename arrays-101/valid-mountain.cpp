#include "stdio.h"
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) {
            return false;
        }
        if (arr[0] >= arr[1] || arr[arr.size() - 2] <= arr[arr.size() - 1]) {
            return false;
        }
        bool increase = true;
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (increase) {
                if (arr[i] == arr[i+1]) {
                    return false;
                }
                if (arr[i] > arr[i+1]) {
                    increase = false;
                }
            } else {
                if (arr[i] <= arr[i+1]) {
                    return false;
                }
            }
        }
        return true;
    }
};