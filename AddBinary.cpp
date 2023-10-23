#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b)
{
   int aIndex = a.length() - 1, bIndex = b.length() - 1;

   int aVal = 0, bVal = 0, carry = 0, sum = 0;

   string result = "";

   while(aIndex >= 0 || bIndex >= 0 || carry)
   {
     aVal = (aIndex >= 0) ? (a[aIndex] - '0') : 0;
     bVal = (bIndex >= 0) ? (b[bIndex] - '0') : 0;

     sum = aVal + bVal + carry;

     carry = (sum > 1) ? 1 : 0;

     result = to_string(sum % 2) + result;

     aIndex--;
     bIndex--;  


   }

   return result;
}

int main()
{
    string a = "11", b = "11";
    string result = addBinary(a,b);

    cout << result;
    
    return 0;
}