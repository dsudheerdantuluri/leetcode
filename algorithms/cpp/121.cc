#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
		{
			if (!prices.size()) return 0;

			int mp = 0, min = prices[0]; 

		  for (auto p : prices) {	
				if ( p > min )
					mp = max(mp, p-min);
				else 
					min = p;
			}

			return mp;
		}
};

int main()
{
	return 0;
}
