#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) 
		{
			 if (nums.size() == 0) return;

       int low = 0, mid = 0, high = nums.size()-1; 

			 while ( mid<=high ) {
					if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
					else if (nums[mid] == 1) mid++; 
					else swap(nums[mid], nums[high--]);
			 }
    }
};


int main()
{
	Solution s;
	//vector<int> v{2,2,1,1,1,0,1,2};
	vector<int> v{1,0};
	//vector<int> v{1,2};
	s.sortColors(v);
	for (auto i:v)
		cout << i << " ";
	cout << endl;
	return 0;
}
