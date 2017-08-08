#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
		{
    	int rd = 0, wr = 0;
			while (rd < nums.size()) {
				int elem = nums[rd];
				while ( (rd<nums.size()) && (nums[rd]==elem) ) rd++;
			  nums[wr++] = elem;
				if (rd-wr>1) nums[wr++] = elem;
			}
			return wr;
    }
};


int main()
{
	vector<int> v{1,1,1,2,2,3};
	Solution s;
	cout << s.removeDuplicates(v) << endl;
	return 0;
}
