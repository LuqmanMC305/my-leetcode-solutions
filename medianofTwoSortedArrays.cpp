#include <iostream>

using namespace std;

void mergeArray(int arrNum1[], int arrNum2[], int size1, int size2)
{
    int size3 = size1 + size2;
    int m = 0, n = 0, k = 0;

    int arrNum3[size3];

    while(m < size1 && n < size2)
    {
        if(arrNum1[m] <= arrNum2[n])
        {
            arrNum3[k] = arrNum1[m];
            m++;
        }
        else
        {
            arrNum3[k] = arrNum2[n];
            n++;
        }

        k++;
    }

    while(m < size1)
    {
        arrNum3[k] = arrNum1[m];
        m++;
        k++;
    }

     while(n < size2)
    {
        arrNum3[k] = arrNum2[n];
        n++;
        k++;
    }

    /*
    for(const auto &element : arrNum3)
    {
        cout << element << " ";
    }

    */

    int mid = size3 / 2;
    double median;

    if(size3 % 2 == 0)
    {
       median = ((static_cast<double>(arrNum3[mid])) + arrNum3[mid -1]) / 2;
    }
    else
    {
        median = arrNum3[mid];
    }

    cout << median;
}

int main()
{
    int arrNum1[] = {1,2};
    int arrNum2[] = {3,4};
    int size1 = sizeof(arrNum1)/sizeof(int);
    int size2 = sizeof(arrNum2)/sizeof(int);

    mergeArray(arrNum1, arrNum2, size1, size2);
    return 0;
}