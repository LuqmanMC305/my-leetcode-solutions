#include <string>
#include <iostream>
#include <climits>

using namespace std;

int myAtoi(string s)
{
    int result = 0;
    int sign = 1; //Default sign operation (+)
    int i = 0;
    
    
    while(i < s.size() && s[i] == ' ') //Ignore whitespaces
    {
        i++;
    }

    
    if(s[i] == '-') //Determine sign operation
    {
        sign = -1;
        i++;
    }
    
    while(i < s.size())
    {
        if(s[i] < 48 || s[i] > 57)
        {
            break;
        }
        
        /*Two conditions to check overflow:
        
         1) If (result * 10) > MAX, since after checking THIS condition, we multiply result with 10.
         2) If the result already exceeded MAX

        */

        if((result > INT_MAX / 10) ||(result == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10)) //(INT_MAX % 10) is 7 at the end of MAX value
        {

            return (sign == -1) ? INT_MIN : INT_MAX;
        }

        result = (result * 10) + (s[i] - '0') * sign; // '0' is 48 in ASCII
        

        i++;

    }

    return result;
}

int main()
{
    string s = "4193 with words";

    cout << myAtoi(s);
}