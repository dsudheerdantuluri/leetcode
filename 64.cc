#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
		{
			if (grid.size() == 0) 
				return 0;

			auto m = grid.size();
			auto n = grid[0].size();

			vector<vector<int>> mps(m, vector<int>(n, 0));

			mps[0][0] = grid[0][0];

			for (int i=1; i<m; ++i)
				mps[i][0] = mps[i-1][0] + grid[i][0];

			for (int j=1; j<n; ++j)
				mps[0][j] = mps[0][j-1] + grid[0][j];	
			
      for (int i=1; i<m; ++i) {
				for (int j=1; j<n; ++j) {
					mps[i][j] = min(mps[i-1][j], mps[i][j-1]) + grid[i][j];
				}
			}

			return mps[m-1][n-1]; 
    }
};

int main()
{
	vector<vector<int>> grid{{1,1,1,1},{2,2,2,2}};
	Solution s;
	cout << s.minPathSum(grid) << endl;
	return 0;
}
