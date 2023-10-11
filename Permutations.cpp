#include <iostream>
#include <vector>
#include <string>

using namespace std;

void recursiveDFS(vector<int> &num, vector<vector<int>> &result, int start)
{
    if(start == num.size()) //Base case
    {
        result.push_back(num); 
        return;
    }

    for(int i = start; i < num.size(); i++)
    {
        swap(num[start], num[i]); //Swap two elements
        recursiveDFS(num, result, start + 1); 
        swap(num[start], num[i]); //Undo swap
    }
}

vector<vector<int>> permute(vector<int> &num)
{
    vector<vector<int>> result;

    recursiveDFS(num, result, 0); //Start begins with 0

    return result;
}

int main()
{
    vector<int> num = {1,2,3};
    
    vector<vector<int>> result = permute(num);

    for(const auto &i : result)
    {
        for(const auto &j : i)
        {
            cout << j << " ";
        }

        cout << endl;
    }

    return 0;
}