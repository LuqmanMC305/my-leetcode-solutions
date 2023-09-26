#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

bool isValid(string s)
{
    vector<char> stack;
    int i = 0;

    unordered_map<char, char> map = 
    {
        {')','('}, 
        {'}','{'}, 
        {']','['}
    };

    while(i < s.size())
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[' )
        {
            stack.push_back(s[i]);
        }

        if(s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if(stack.back() == map[s[i]])
            {
                stack.pop_back();
               
            }
            else
            {
                return false;
            }
        }
        
        i++;


    }
    
    return stack.empty();


}

int main()
{
    string s = "(((())))";

    if (isValid(s))
    {
        cout << "Valid." << endl;
    }
    else
    {
        cout << "Not valid." << endl;
    }

 


    return 0;
}