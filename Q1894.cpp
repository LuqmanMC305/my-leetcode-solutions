//Find the Student that Will Replace the Chalk
#include <vector>
#include <iostream>

using namespace std;

int chalkReplacer(vector<int> &chalk, int k)
{
   int sum = 0;
   
   //Calculate sum of chalk
   for(int i = 0; i < chalk.size(); i++)
   {
     sum += chalk[i];
   }

   if(sum <= 0)
   {
     return -1;
   }
   
   //Ensure the iteration is only one cycle (reduce k value)
   k %= sum; 

   for(int j = 0; j < chalk.size(); ++j)
   {
      if((k - chalk[j]) < 0)
      {
        return j;
      }
      else
      {
        k -= chalk[j];
      }

   }

   return 0;

}

int main()
{
    vector<int> chalk = {0,0,0};
    int k = 15;

    cout << chalkReplacer(chalk, k);
    return 0;
}