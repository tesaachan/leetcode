#include "vector"
#include "iostream"
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int count = 0;
    int j = nums.size() - 1;
    while (j >= 0 && nums[j] == val) {
        j--;
        count++;
    }
    for (int i = j - 1; i >= 0; i--) {
        if (nums[i] == val) {
            swap(nums[i], nums[j]);
            j--;
            count++;
        }
    }
    return nums.size() - count;
}

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    cout << removeElement(nums, 2) << endl;
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
}
