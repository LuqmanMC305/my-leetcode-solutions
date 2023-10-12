#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t)
{
    unordered_map<char, int> map;

    if(s.length() != t.length())
    {
        return false;
    }


    //Count frequency of letter in s
    for(const auto &letter : s)
    {
        map[letter]++;
    }
    
    //Decrement the frequency
    for(const auto &letter : t)
    {
        map[letter]--;
    }
    
    //If all key values are 0, both of words have same letter frequency 
    for(const auto &freq : map)
    {
        if(freq.second != 0)
        {
            return false;
        }
    }

    return true;

}
int main()
{
    string s = "aangram", t = "nagaram";

    if(isAnagram(s, t))
    {
        cout << "Anagram" << endl;
    }
    else
    {
        cout << "Not an anagram" << endl;
    }
    return 0;
}