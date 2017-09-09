#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:

		int getNumPowers(int n, int b)
		{
			int count = 0;
			
			if ( n == 0 ) return count;

			while ( n >= b ) {

				count += n / b;

				n /= b;

			}

			return count;
		} 

    int trailingZeroes(int n) {

			auto numPowers2 = getNumPowers(n, 2);
			
			auto numPowers5 = getNumPowers(n, 5);

			return min(numPowers2, numPowers5);	        
    }
};

int main()
{

	Solution s;
		
	cout << s.trailingZeroes(5) << endl;
	return 0;
}
