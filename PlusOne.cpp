#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
   int lastDigit = digits.size() - 1, carryOne = 1; //Initialise carry to one to add one
   
   while(lastDigit >= 0)
   {
     int sum = digits[lastDigit] + carryOne;
     if(sum <= 9)
     {
        digits[lastDigit] = sum;
        return digits;
     }
     else
     {
        digits[lastDigit] = sum % 10;
        carryOne = 1;
     }

     lastDigit--;
   }
   
   // If add one resulting an extra digit
   vector<int> extraDigit(digits.size() + 1);
   extraDigit[0] = 1;

   for(int i = 1; i < extraDigit.size() - 1; i++)
   {
     extraDigit[i] = 0;
   }

   return extraDigit;
  
}

int main()
{
    vector<int> digits = {1,2,4};
    vector<int> result = plusOne(digits);

    for(const int &element : result)
    {
        cout << element << " ";
    }

    return 0;
}