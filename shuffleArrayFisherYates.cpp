#include <iostream>
#include <string>
#include <vector>
#include <time.h>


class Solution
{
    private:

      std::vector<int> original;
      

    public:
       Solution(std::vector<int> &arrNum)
       {
         original = arrNum;
       }

       std::vector<int> reset()
       {
         return original;
       }

       std::vector<int> shuffle()
       {
          std::vector<int> shuffled = original;
          int n = original.size();

          for(int i = n - 1; i >= 0; i--)
          {
             int j = rand() % (i + 1);
             
             int temp = shuffled[i];
             shuffled[i] = shuffled[j];
             shuffled[j] = temp;


          }

           return shuffled;
       }


};

int main()
{
   srand(time(NULL));
   std::vector<int> arrNum{1,2,3,4,5};

   Solution s1(arrNum);
   
   std::vector<int> result = s1.shuffle();
   std::vector<int> reset = s1.reset();

   for(const auto &i : result)
   {
      std::cout << i << " ";
   }

   return 0;
}