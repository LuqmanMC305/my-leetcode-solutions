#include <iostream>

using namespace std;

int removeElements(int arrNum[], int size, int target)
{
    int newLength = 0;

    for(int i = 0; i < size; i++)
    {
        if(arrNum[i] != target)
        {
           arrNum[newLength] = arrNum[i];
           newLength++;
        }
    }

    return newLength;
}

int main()
{
    int arrNum[] = {0,1,2,2,3,0,4,2};
    int target = 2;
    int size = sizeof(arrNum)/sizeof(arrNum[0]);

    int newSize = removeElements(arrNum, size, target);

    cout << "New length: " << newSize << endl;
    cout << "Modified Array: ";
    
    for(int i = 0; i < newSize; i++)
    {
        cout << arrNum[i] << " ";
    }

    return 0;
}