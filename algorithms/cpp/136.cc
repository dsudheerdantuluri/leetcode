#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
			auto sum = 0;
			for (auto i: nums) sum = sum ^ i;
      return sum;  
    }
};

int main()
{

	return 0;
}
