#include "vector"
#include "iostream"
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int c = 0;
    for (int i = 0; i < nums.size() - c; i++)
    {
        if (nums[i] == val)
        {
            c++;
            int j = i;
            while (j < nums.size() - c)
            {
                nums[j] = nums[j+1];
                j++;
            }
            i--;
        }
    }
    return (nums.size() - c);
}

int main()
{
    vector<int> nums = {3,3};
    cout << removeElement(nums, 3) << endl;
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
}
