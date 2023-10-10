#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{ 
   vector<vector<int>> ans(numRows);

   for(int row = 0; row < numRows; row++)
   {
      ans[row].resize(row+1);
      ans[row][0] = 1; //Leftmost column is always 1

      for(int col = 1; col < row; col++)
      {
         ans[row][col] = ans[row-1][col-1] + ans[row-1][col]; //Calculate the numbers in middle columns
      }

      ans[row][row] = 1; //Rightmost column is always 1
   }

   return ans;
}

int main()
{
    int numRows = 4;
    vector<vector<int>> triangle = generate(numRows);

    for(const auto &i : triangle)
    {
        for(const auto &j : i)
        {
           cout << j << " ";
        }

        cout << endl;
    }


    return 0;
}