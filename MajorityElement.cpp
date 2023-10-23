//Using Boyer-Moore majority vote algorithm
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int majorityElement(vector<int> &nums)
{
   int majorityElement = 0;
   int count = 0;
   int frequency = 0;

   for(const int &element : nums)
   {
      if(count == 0)
      {
         majorityElement = element;
      }
      else if(majorityElement == element)
      {
        count++;
      }
      else
      {
        count--;
      }
   }
   
   //Check if element frequency is more than (n / 2) times
   for(const int &element : nums)
   {
       if(element == majorityElement)
       {
         frequency++;
       }
   }

  if(frequency > (nums.size() / 2))
   {
     return majorityElement;
   }


   return -1;
}

int main()
{
   vector<int> nums = {2,2,1,1,1,2};
   cout << majorityElement(nums);
}