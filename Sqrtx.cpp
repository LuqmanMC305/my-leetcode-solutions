#include <iostream>

using namespace std;

int mySqrt(int x)
{
    if(x == 0)
    {
        return x;
    }

   int left = 1;
   int right = x;
   int result = 0;

   while(left < right)
   {
      int mid = left + (right - left) / 2;

      if((mid * mid) > x)
      {
         right = mid - 1;
      }
      else if((mid * mid) < x)
      {
        left = mid + 1;
        result = mid;
      }
      else
      {
       return mid; //If mid^2 == x 
      }
    
   }

   return result;
    
}
int main()
{
    int x = 144;
    cout << mySqrt(x);

    return 0;
}