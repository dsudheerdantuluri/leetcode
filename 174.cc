#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
	public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
		{
			int m = dungeon.size();

			if (m == 0) return 1;

			int n = dungeon[0].size();

			if (n == 0) return 1;

			vector<vector<int>> minHP(m+1, vector<int>(n+1, numeric_limits<int>::max()));

			minHP[m][n-1] = 1;

			minHP[m-1][n] = 1;

			for (int i = m - 1;  i >= 0 ; --i ) {
				for (int j = n - 1; j >= 0 ; --j ) {
					int need = min(minHP[i+1][j], minHP[i][j+1]) - dungeon[i][j];
					minHP[i][j] = (need <= 0) ? 1 : need; 
				}
			}

			return minHP[0][0];
    }
};

int main()
{
	return 0;
}
