#include <iostream>

using namespace std;

int add(int a, int b)
{
     int carry;

     while(b)
     {
        carry = a & b;
        a = a ^ b;
        b = carry << 1;
     }

     return a;
}

int main()
{
    int x = 5, y = 3;
    
    cout << add(x, y) << endl;
    return 0;
}