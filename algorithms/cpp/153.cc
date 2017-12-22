#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

       if (nums.size() == 1) return nums[0];

       return findMin(nums, 0, nums.size() - 1); 
    }   

    int findMin(vector<int> &nums, int low, int high)
    {   
      int mid = low + (high - low)/2;
    
      //already sorted
      if ( (nums[low] < nums[high]) ) return nums[low];

      if ( nums[mid] > nums[mid+1] ) return nums[mid+1];

      if ( nums[low] < nums[mid] ) return findMin(nums, mid, high);

      else return findMin(nums, low, mid);
    }   
};


int main()
{
	return 0;
}
