#include <iostream>

using namespace std;

class Solution {

	public:
    uint32_t reverseBits(uint32_t n) 
		{
			uint32_t result = 0;

			uint32_t count = 0;

			while ( n != 0 ) {

				result <<= 1;

				result |= (n % 2);

				count++;

				n /= 2;
			}

			//cout << count << endl;

			result = result << (32 - count);

			return result;	
    }
};

int main()
{
	Solution s;
	cout << s.reverseBits(1) << endl;
	cout << s.reverseBits(2147483648) << endl;
	return 0;
}
