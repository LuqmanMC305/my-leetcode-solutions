#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(int arrNum[], int target, int size)
{
    std::vector<int> indicesSum;
    std::unordered_map<int, int> map;
    int diff;

    for(int i = 0; i < size; i++)
    {
        diff = target - arrNum[i];

        if (map.find(diff) != map.end())
        {
            indicesSum.push_back(map[diff]);
            indicesSum.push_back(i);
            

            return indicesSum;
        }
        else
        {
            map[arrNum[i]] = i;
        }
    }

    indicesSum.push_back(-1);
    return indicesSum;


}

int main()
{   
    //Test cases
    int arrNum[] = {2,5,11,0};
    int target = 2;
    int size = sizeof(arrNum)/sizeof(arrNum[0]);

    std::vector<int> indices = twoSum(arrNum, target, size);

    if (indices.back() == -1)
    {
        std::cout << "Index not found. " << std::endl;
    }
    else
    {
        std::cout << "Indices found at: " << indices[0] << " " << indices[1] << std::endl;
    }


    return 0;
}

