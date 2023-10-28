#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
   int n = nums.size();
   
   //Base cases
   if(n == 0)
   {
      return 0;
   }
   else if (n == 1)
   {
     return nums[0];
   }

   int memo[n];
   memo[0] = nums[0]; 
   memo[1] = max(nums[0], nums[1]);
  
   /* 
    
    2 options:
      1) Skip current house & maintain the current loot
      2) Rob the current house & add it with max loot obtained two steps behind current house

      Find max between these 2 options
   */
   for(int i = 2; i < n; i++)
   {
      memo[i] = max(memo[i-1], memo[i-2] + nums[i]); 
   }

   return memo[n-1];


}

int main()
{
    vector<int> houses = {40,2,4,10};
    cout << rob(houses);

    return 0;
}
