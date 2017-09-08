#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) 
		{
			if (nums.size() == 0) return 0;

			int low = 0;
			int high = nums.size() - 1;

			while (low != high) {

				int mid = low + (high - low)/2;

				if (nums[mid] > nums[mid+1] ) {
					high = mid;
				} else {
					low = mid+1;
				}
			}

			return low;
    }
};

int main()
{
	return 0;
}
