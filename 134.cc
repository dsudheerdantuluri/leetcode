#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
			
			int startIndex = 0, startSlack = 0, tns = 0, n = gas.size();

			for (int i = 0 ; i < n ; ++i) {

				int curSlack = gas[i] - cost[i];

				startSlack += curSlack;

				if ( startSlack < 0 ) {
					tns += startSlack;
					startSlack = 0;
					startIndex = i+1;
				}
			}

			startSlack += tns;

			return (startSlack < 0) ? -1 : startIndex;

    }
};

int main()
{

	return 0;
}
