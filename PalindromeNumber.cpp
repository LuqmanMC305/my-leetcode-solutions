#include <iostream>

using namespace std;

bool isPalindrome(int num)
{
    if (num < 0)
    {
        return false;
    }

    int divisor = 1;
    int left, right;

    //Ensure divisor have same zeros as num
    while(divisor * 10 < num)
    {
        divisor *= 10;
    }

    while(num > 0)
    {
        left = num / divisor; 
        right = num % 10;

        if(left != right)
        {
            return false;
        }

        
        num = num % divisor; //Cut leftmost number
        num = num / 10;     // Cut rightmost number

        divisor /= 100; //Since two digits of num are removed, we remove two digits of divisor

    }

    return true;
}

int main()
{
    int num = 121;
    
    if(isPalindrome(num))
    {
        cout << "This is a palindrome" << endl;
    }
    else
    {
       cout << "Not a palindrome" << endl;
    }

    return 0;
}