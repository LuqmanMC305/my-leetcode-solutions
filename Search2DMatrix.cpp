#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &array, int target)
{
    if(array.size() == 0) return false;
    
    int currRow = 0, currCol = array[0].size() - 1;

    while(currRow < array.size() && currCol >= 0)
    {
        if(target > array[currRow][currCol] )currRow++;
        else if(target < array[currRow][currCol]) currCol--;
        else return true;
    }

    return false;
}

int main()
{
    vector<vector<int>> arrNum {
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60}
    };

    int target = 60;

    if(searchMatrix(arrNum, target)) cout << "True" << endl;
    else cout << "False" << endl;
}