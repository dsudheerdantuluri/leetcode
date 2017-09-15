#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	public:
		int maxProfit(int k, vector<int>& prices) {

			int n = prices.size();

			if ( (k<1) || (n<2) ) return 0;

			if ( n/2 <= k ) {
				int profit = 0;
				for (int i = 1; i < n; ++i ) {
					if (prices[i] > prices[i-1])	{
						profit += (prices[i] - prices[i-1]);
					}
				}
				return profit;
			}

			int rel[k+1];
			int hold[k+1];

			for (int i = 0; i <= k; ++i ) {
				rel[i] = 0;
				hold[i] = numeric_limits<int>::min();
			}

			for (int i = 0; i < n; ++i ) {
				int cur = prices[i];
				for (int j = k; j > 0; --j) {
					rel[j] = max(rel[j], hold[j-1] + cur);
					hold[j] = max(hold[j], rel[j-1] - cur);
				} 
			}

			return rel[k];
		}
};

int main()
{
	vector<int> v{1,2};
	Solution s;

	cout << s.maxProfit(1, v) << endl;
	return 0;
}
