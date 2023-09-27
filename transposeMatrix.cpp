#include <iostream>
#include <vector>

using namespace std;



vector<vector<int>> transpose(vector<vector<int>> &arrNum)
{
 
  int i = arrNum.size(); //No. rows
  int j = arrNum[0].size(); //No. cols

  vector<vector<int>> trans(i, vector<int>(j)); //Create new matrix to transpose
  
  for(int row = 0; row < i; row++)
  {
    for(int col = 0; col < j; col++)
    {
        trans[row][col] = arrNum[col][row];
    }
  }
  
  return trans;
}

int main()
{

   vector<vector<int>> arrNum = 
   {
    {1,2,3}, 
    {4,5,6}, 
    {7,8,9}
   };

   vector<vector<int>> transposed = transpose(arrNum);

   //Print the transposed matrix

   for(int row = 0; row < arrNum.size(); row++)
   {
     for(int col = 0; col < arrNum[0].size(); col++)
     {
        cout << transposed[row][col] << " ";
     }

     cout << endl;
   }

   return 0;
}