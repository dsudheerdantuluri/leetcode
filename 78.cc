#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
		void subsetsRec(vector<int> &nums, vector<bool> &inc, vector<vector<int>> &result, int change)
		{
			if (change == nums.size()) {
				vector<int> re;
				for (int i=0; i<nums.size(); ++i) {
					if (inc[i]) {
						re.emplace_back(nums[i]);
					}
				}
				result.emplace_back(re);
				return;
			}

			for (int i = 0; i <= 1; ++i) {
				inc[change] = i;
				subsetsRec(nums, inc, result, change+1);
			}
		}

    vector<vector<int>> subsets(vector<int>& nums) 
		{
    	vector<vector<int>> result;
			
			vector<bool> inc(nums.size(), false);
			subsetsRec(nums, inc, result, 0);

			return result; 
    }
};

int main()
{
	Solution s;
	vector<int> v{1,2,3};
	for (const auto &vi: s.subsets(v)) {
		for (auto i: vi) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
