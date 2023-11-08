#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void backtrack(vector<int> &tempList, vector<vector<int>> &result, vector<int> &num)
{
  if(tempList.size() == num.size())
  {
    result.push_back(tempList);
    return;
  }
  else
  {
    for(int i = 0; i < num.size(); i++)
    {
        if(find(tempList.begin(), tempList.end(), num[i]) != tempList.end()) continue;
        else tempList.push_back(num[i]);

        backtrack(tempList, result, num);
        tempList.pop_back();
    }
  }
}

vector<vector<int>> permute(vector<int> &num)
{
    vector<vector<int>> result;
    vector<int> tempList;

    backtrack(tempList, result, num); //Start begins with 0

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