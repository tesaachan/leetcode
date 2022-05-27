#include "vector"
#include "iostream"
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int cur = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != nums[cur])
        {
            cur++;
            nums[cur] = nums[i];
        }
    }
    return cur + 1;
}

int main()
{
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(nums) << endl;
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << ' ';
}
