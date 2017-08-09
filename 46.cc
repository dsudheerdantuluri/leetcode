#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    void permute(vector<int>& nums, int ci, vector<vector<int>> &result) {

			if (ci == nums.size()) {
				result.emplace_back(nums);
				return;
			}

			for (int i = ci; i < nums.size(); ++i) {
				swap(nums[ci], nums[i]);
				permute(nums, ci+1, result);
				swap(nums[i], nums[ci]);	
			}	

		}
	
public:
    vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> result;
			permute(nums, 0, result);
			return result;
    }
};


int main()
{
	Solution s;
	vector<int> nums{1,2,3};
	auto vvi = s.permute(nums);
	for (const auto &vi : vvi) {
		for (const auto i : vi) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
