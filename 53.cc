#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
		{
			auto curSum = 0, maxSum = INT_MIN;
			for (auto num: nums) {
				curSum += num;
				if (curSum > maxSum) {
					maxSum = curSum;
				}
				if (curSum < 0) {
					curSum = 0;
				} 
      }
			return maxSum;
    }
};

int main()
{
	Solution s;
	vector<int> v({-2,1,-3,4,-1,2,1,-5,4});
	cout << s.maxSubArray(v) << endl;
	return 0;
}
