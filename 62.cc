#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) 
		{
			vector<vector<int>> numUniqPaths(m,vector<int>(n,1));
       
			for (int i = 1; i < m; ++i) {
				for (int j = 1; j < n; ++j) {
					numUniqPaths[i][j] = numUniqPaths[i-1][j] + numUniqPaths[i][j-1];
				}
			}

			return numUniqPaths[m-1][n-1]; 
    }
};

int main()
{
	Solution s;
	cout << s.uniquePaths(3,7) << endl;
	return 0;
}

