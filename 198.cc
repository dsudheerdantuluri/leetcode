#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) 
		{

			if (nums.size() == 0) return 0;

			int slmax = 0;

			int lmax = nums[0];

			for ( int i = 1 ; i < nums.size();  ++i ) {

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
};

int main()
{
		return 0;
}
