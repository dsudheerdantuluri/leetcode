#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int findMin(vector<int>& nums) 
		{
       if (!nums.size()) return 0;

			 return findMin(nums, 0, nums.size() - 1);
    }

		int findMin(vector<int> &nums, int low, int high)
		{
			if (low == high) return nums[low];
      
			//already sorted
      if ( (nums[low] < nums[high]) ) return nums[low];
			
			int mid = low + (high - low)/2;

			if ( nums[mid] > nums[mid+1] ) return nums[mid+1];

			if ( nums[low] < nums[mid] ) return findMin(nums, mid, high);

			else if ( nums[mid] < nums[high] ) return findMin(nums, low, mid);

			else return min(findMin(nums, low, mid), findMin(nums, mid+1, high));
		}
};

int main()
{
	return 0;
}
