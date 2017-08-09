#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
	public:
    bool canJump(vector<int>& nums) 
		{
			int maxPos = 0;
			for (int i = 0; (i < nums.size()-1) && (i <= maxPos) ; ++i)
				maxPos = max(maxPos, i+nums[i]);
			return maxPos >= nums.size()-1;
    }
};

int main()
{
	Solution s;
	vector<int> v1({2,3,1,1,4});
	cout << s.canJump(v1) << endl;
	vector<int> v2({3,2,1,0,4});
	cout << s.canJump(v2) << endl;
	vector<int> v3({0,2,3});
	cout << s.canJump(v3) << endl;
	vector<int> v4({3,0,8,2,0,0,1});
	cout << s.canJump(v4) << endl;
	return 0;
}
