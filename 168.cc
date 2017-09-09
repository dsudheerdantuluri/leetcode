#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
       
			string result("");

			while ( n > 0 ) {

				result += (n-1)%26 + 'A';

				n = (n-1)/26;

			}

			reverse(result.begin(), result.end());

			return result; 
    }
};

int main()
{
	return 0;
}
