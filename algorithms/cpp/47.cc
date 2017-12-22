#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
private:
    void permuteUnique(vector<int>& nums, int ci, vector<vector<int>> &result) {

			if (ci == nums.size()) {
				result.emplace_back(nums);
				return;
			}

			set<int> uniq;
			for (int i = ci; i < nums.size(); ++i) {
				if (uniq.find(nums[i]) == uniq.end()) {
					swap(nums[ci], nums[i]);
					permuteUnique(nums, ci+1, result);
					swap(nums[i], nums[ci]);
					uniq.insert(nums[i]);	
				}
			}	

		}
	
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
			vector<vector<int>> result;
			permuteUnique(nums, 0, result);
			return result;
    }
};


int main()
{
	Solution s;
	vector<int> nums{1,1,2,2};
	auto vvi = s.permuteUnique(nums);
	for (const auto &vi : vvi) {
		for (const auto i : vi) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
