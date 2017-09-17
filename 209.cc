#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
			if (nums.size() == 0ul) return 0;
			auto i = 0ul, j = 0ul, n = nums.size();
			auto ml = numeric_limits<decltype(n)>::max();
			auto sum = nums[0];
			while (i < n) {
				if (sum >= s) ml = min(ml, j-i+1);
				if ( ((j+1) < n) && (sum < s) ) sum += nums[++j];
				else sum -= nums[i++];
			}
			return (ml == numeric_limits<decltype(n)>::max()) ? 0 : ml; 
    }
};

int main()
{

	return 0;
}
