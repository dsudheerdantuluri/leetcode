#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
		{
			auto n = nums.size();

			if	( (n < 2) || (k == n) ) return; 
       
			if ( k > n ) k = k % n;

			int count = 0;

			for ( int i = 0; count < n; ++i ) {
				int start = i;
				int temp = nums[start];
				do {
					auto newPos = (start + k) % n;
					auto prev = nums[newPos];
					nums[newPos] = temp;
					temp = prev;	
					start = newPos;
					count++;
				} while (start != i);
			} 
    }
};

int main()
{
	return 0;
}
