#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
			auto m = grid.size();
			if ( m == 0 ) return 0;
			auto n = grid[0].size();
			int count = 0;
			for (decltype(m) i = 0; i < m; ++i) {
				for (decltype(n) j = 0; j < n; ++j) {
					if (grid[i][j] == '1') {
						markX(grid, i, j, m, n);
						++count;
					}
				}
			}
			return count;        
    }

		void markX(vector<vector<char>> &grid, int i, int j, int m, int n)
		{
			if ( (i<0) || (i>=m) ) return;
			if ( (j<0) || (j>=n) ) return;
			if ( grid[i][j] != '1' ) return;
			grid[i][j] = 'x';
			markX(grid, i+1, j, m, n);
			markX(grid, i-1, j, m, n);
			markX(grid, i, j+1, m, n);
			markX(grid, i, j-1, m, n);
		}	
};

int main()
{

	return 0;
}
