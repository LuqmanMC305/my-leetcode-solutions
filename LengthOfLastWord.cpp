#include <iostream>
#include <string>

using namespace std;

int lastWordLength(string s)
{
    int length = 0;

    if(s.length() == 0) return 0;

    for(int i = s.length() - 1; i >=0; i--)
    {
        if(s[i] != ' ') length++;

        if(s[i] != ' ' && s[i-1] == ' '  && i > 0) break;
    }

    return length;


}

int main()
{
    string s = "a vdgd  ";
    cout << lastWordLength(s) << endl;
    return 0;
}