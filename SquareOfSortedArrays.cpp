#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    vector<int> result(nums.size());
    int left = 0, right = nums.size() - 1;

    int index = nums.size() - 1;

    while(index >= 0)
    {
        if(abs(nums[right]) > abs(nums[left]))
        {
            result[index] = nums[right] * nums[right];
            right--;
        }
        else
        {
            result[index] = nums[left] * nums[left];
            left++;
        }

        index--;
    }

    return result;
    
}

int main()
{
    vector<int> nums = {-7, -3,2,3,11};
    vector<int> result = sortedSquares(nums);

    for(const int &num : result)
    {
        cout << num << " ";
    }

    return 0;
}