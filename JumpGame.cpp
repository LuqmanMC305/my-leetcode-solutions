//Using greedy algorithm
#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int> &nums)
{
    int goal = nums.size() - 1; //Initial goal is the last index

    //Reverse iteration
    for(int i = goal; i >=0; i--)
    {
        if (i + nums[goal] >= goal) //If reaches the goal 
        {
           goal = i; //Current index becomes the new goal 
        } 
    }

    return goal == 0; //If goal reaches the starting element

    

}

int main()
{
    vector<int> numArray = {3,2,1,0,4};
    cout << canJump(numArray);
    return 0;
}