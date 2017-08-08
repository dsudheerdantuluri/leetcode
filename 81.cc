#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
	int search(vector<int>& nums, int target) 
	{
		if (!nums.size()) return 0;

		int low = 0, high = nums.size()-1;


		while (low <= high) {
      
      int mid = low + (high-low)/2;

			if (nums[low]==target || nums[mid] == target || nums[high]==target) return true;
      
      if ( nums[high] > nums[mid] ) {

        if ( target > nums[mid] && target < nums[high] ) 
        	low = mid+1;		
				else
					high = mid-1;

      } else if ( nums[high] < nums[mid] ) {

				if ( target > nums[low] && target < nums[mid] )
					high = mid-1;
        else 
          low = mid+1;

			} else {

        --high;
     
		  }

    }

	  return false;	
	}
};


int main()
{
	Solution s;
	vector<int> v1{1,3};
	vector<int> v2{1,3,1,1,1};
	cout <<	s.search(v1,3) << endl;
	cout <<	s.search(v2,3) << endl;
	return 0;
}

