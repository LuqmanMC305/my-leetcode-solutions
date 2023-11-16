#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s)
{
    if (s.empty() || s.length() == 1) return s;
    
    int n = s.length(), startIndex = 0, subStringLength = 0, left, right;

    for(int i = 0; i < n; i++)
    {
        //For odd length string
        left = right = i;
        while(left >= 0 && right < n && s[left] == s[right]) 
        {
            if((right - left + 1) > subStringLength) // "aba" length is (2-0+1) = 3
            {
                startIndex = left; //Set the current beginning index 
                subStringLength = right - left + 1; //Find the current substring length
            }

            left--; //Left will become out of bound (0 -> -1)
            right++;
        }

        //For even length
        left = i, right = i + 1; //Reinitialise left and right
        while(left >= 0 && right < n && s[left] == s[right]) 
        {
            if((right - left + 1) > subStringLength) 
            {
                startIndex = left; 
                subStringLength = right - left + 1; 
            }

            left--;
            right++;
        }
    }

    return s.substr(startIndex, subStringLength); //Return the final answer by slicing 
    

}

int main()
{
    string s = "cbba";

    cout << longestPalindrome(s) << endl;
    return 0;
}