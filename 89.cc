#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution 
{
	public:
    vector<int> grayCode(int n) 
		{
			vector<int> result{0, 1};
			int inc = 2;
			for (unsigned i = 2; i <= n ; ++i) {
				result.insert(result.end(), result.rbegin(), result.rend());
				auto x = pow(2, i-1);
				for (auto k = x; k < result.size() ; ++k) {
					result[k] += inc;
				}
				inc *= 2;
			}

			return result;
    }
};

int main()
{
	Solution s;
	for (auto i: s.grayCode(4))
		cout << i << endl;
	return 0;
}
