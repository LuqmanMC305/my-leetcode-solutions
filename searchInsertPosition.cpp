#include <iostream>

using namespace std;

int search(int arrNum[], int target, int left, int right)
{

    if(left > right)
    {
        if(target > arrNum[left])
        {
            return (left + 1);
        }
        else
        {
            return (left);
        }
        
    }

    int mid = (left + right) / 2;

    if(arrNum[mid]== target)
    {
        return mid;
    }
    else if(target > arrNum[mid])
    {

        return search(arrNum, target, mid + 1, right);
    }
    else
    {
         return search(arrNum, target, left, mid - 1);
    }

}

int main()
{
    int arrNum[] = {1,3,5,6};
    int target = 0;
    int left = 0;
    int right = (sizeof(arrNum)/sizeof(int)) - 1;


    cout << search(arrNum, target, left, right);
    return 0;
}