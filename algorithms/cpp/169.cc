#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) 
		{
			int count = 1;
			int major = nums[0];
			for (int i = 1; i < nums.size(); ++i) {
				if (count == 0) {
					major = nums[i];
					count = 1;
				} else if ( nums[i] == major ) ++count;
				else count--;	
			}
			return major;
    }
};

int main()
{

	return 0;
}

