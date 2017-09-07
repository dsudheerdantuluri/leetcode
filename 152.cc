#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) 
		{
			 if (!nums.size()) return 0;

			 int result, minProd, maxProd;
	
			 result = minProd = maxProd = nums[0];

			 for (int i = 1 ; i < nums.size(); ++i ) {

				if ( nums[i] < 0 )
					swap(minProd, maxProd);

			 	minProd = min(nums[i], minProd * nums[i]);
			  maxProd = max(nums[i], maxProd * nums[i]);

				result = max(maxProd, result);

			 }

			 return result;        
    }
};

int main()
{
	return 0;
}
