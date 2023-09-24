#include <iostream>
#include <unordered_map>
#include <vector>

bool isDuplicate(std::vector<int> arrNum)
{
   std::unordered_map<int, int> map;

   for(const auto &element : arrNum)
   {
      int toFind = element;
      auto iterator = map.find(toFind);

      if(iterator == map.end())
      {
         map[element] = 1;
      }
      else
      {
         map[element]++;
      }

      if(map[element] > 1)
      {
         return true;
      }

   }

   return false;
}

int main()
{
   std::vector<int> arrNum;
   int num;

   do
   {
      std::cout << "Enter the elements of array: " << std::endl;
      std::cin >> num;
      arrNum.push_back(num);
   } while (num != -1);
   
   
   if(isDuplicate(arrNum))
   {
      std::cout << "Contains duplicate numbers." << std::endl;
   }
   else
   {
      std::cout << "Doesn't contain duplicate numbers." << std::endl;
   }
   return 0;
}