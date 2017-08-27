#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
		{
			int numBits = sizeof(int)*8;

			int result = 0;
			for (int i = 0; i < numBits; ++i) {
				int count = 0;
      	for (auto num : nums) {
					if ( (num >> i) & 1 ) ++count;
				} 
				if (count%3) result |= (1 << i);
			}

			return result;
    }
};

int main()
{

	return 0;
}
