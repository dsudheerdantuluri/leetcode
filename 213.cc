#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int straight_rob(vector<int>& nums, int low, int high) 
	{   
		int slmax = 0;
		int lmax = nums[low];
		for ( int i = low+1 ; i <= high; ++i ) { 
			auto ppsum = slmax + nums[i];
			if ( ppsum > lmax ) { 
				auto temp = lmax;
				lmax = slmax + nums[i];
				slmax = temp;
			} else {
				slmax = lmax;
			}
		}   
		return lmax;
	}
  int rob(vector<int>& nums) {
  	if (nums.size() == 0) return 0;
		if (nums.size() == 1) return nums[0];
		return max(straight_rob(nums, 0, nums.size() - 2), straight_rob(nums, 1, nums.size() - 1));
  }   
};

int main()
{
	//vector<int> nums{1,1,3,6,7,10,7,1,8,5,9,1,4,4,3};
	vector<int> nums{2,2,4,3,2,5};
	Solution s;
	cout << s.rob(nums) << endl;
	return 0;
}
