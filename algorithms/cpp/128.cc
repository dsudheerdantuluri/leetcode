#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
		{
    	if (nums.size() == 0) return 0;

			make_heap(nums.begin(), nums.end()); 

			auto prev = nums.front();

			pop_heap(nums.begin(), nums.end()); nums.pop_back();

			int count = 1; 

			int maxCount = 1;

			while (nums.size()) {

				auto curr = nums.front();

				if (curr == (prev - 1)) ++count;
				else if (curr != prev) count = 1;

				maxCount = max(maxCount, count);

				prev = curr;

				pop_heap(nums.begin(), nums.end()); nums.pop_back();

			}

			return maxCount;
    }
};

int main()
{
	Solution s;
	//cout << s.longestConsecutive() << endl;
	return 0;
}
