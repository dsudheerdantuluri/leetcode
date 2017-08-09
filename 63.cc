#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
		{
			if (!obstacleGrid.size()) {
				return 0;
			}

			auto m = obstacleGrid.size();
			auto n = obstacleGrid[0].size();

			vector<vector<int>> numUniqPaths(m,vector<int>(n,!obstacleGrid[0][0]));

			for (int i = 1; i < m; ++i) 
				numUniqPaths[i][0] = obstacleGrid[i][0] ? 0 : numUniqPaths[i-1][0];
			
			for (int j = 1; j < n; ++j) 
				numUniqPaths[0][j] = obstacleGrid[0][j] ? 0 : numUniqPaths[0][j-1];
       
			for (int i = 1; i < m; ++i) {
				for (int j = 1; j < n; ++j) {
					numUniqPaths[i][j] = (obstacleGrid[i-1][j] ? 0 : numUniqPaths[i-1][j]) + (obstacleGrid[i][j-1] ? 0 : numUniqPaths[i][j-1]);
				}
			}

			return obstacleGrid[m-1][n-1] ? 0 : numUniqPaths[m-1][n-1];
    }
};

int main()
{
	Solution s;
	vector<vector<int>> obstacleGrid1{{0,0,0},{0,1,0},{0,0,0}};
	cout << s.uniquePathsWithObstacles(obstacleGrid1) << endl;
	vector<vector<int>> obstacleGrid2{{1}};
	cout << s.uniquePathsWithObstacles(obstacleGrid2) << endl;
	vector<vector<int>> obstacleGrid3{{1,0}};
	cout << s.uniquePathsWithObstacles(obstacleGrid3) << endl;
	return 0;
}

