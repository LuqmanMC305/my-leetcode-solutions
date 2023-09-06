#include <iostream>
#include <vector>

std::vector<int> shuffle (int arrNum[] , int n, int size)
{
   std::vector<int> shuffledArr;
   
   
   for(int i = 0; i < n; i++)
   {
      shuffledArr.push_back(arrNum[i]);
      shuffledArr.push_back(arrNum[n + i]);
   }
      

   return shuffledArr;
}

int main()
{
    //Test cases
    int arrNum[] = {1,1,2,2};
    int n = 2;
    int size = sizeof(arrNum)/sizeof(arrNum[0]);

    std::vector<int> shuffledArr = shuffle(arrNum, n, size);


    for(const auto &index : shuffledArr)
    {
        std::cout << index << " ";
    }
    return 0;
}