#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
		{
			if (!prices.size()) return 0;

			int mxPrice = 0, result = 0;

			int mxProfit = 0;

			vector<int> mxProfits(prices.size(), 0);

			for (int i = prices.size() - 1; i >= 0; --i) {
				mxProfit = max(mxProfit, mxPrice - prices[i]);
				mxPrice = max(mxPrice, prices[i]);
				mxProfits[i] = mxProfit;
			}
	
			int minPrice = prices[0];
			mxProfit = 0;

			for (int i=1; i < prices.size() - 1; ++i) {
				mxProfit = max(mxProfit, prices[i]-minPrice);
				minPrice = min(minPrice, prices[i]);
				result = max(result, mxProfit + mxProfits[i+1]);
			}

			return result;
			
    }
};


int main()
{

	return 0;
}
