#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
		{
			if (matrix.size()==0) return;
	
			auto m = matrix.size();
			auto n = matrix[0].size();

			vector<int> rows, cols;
		
			for (auto i=0; i<m; ++i) {
				for (auto j=0; j<n; ++j) {
					if (matrix[i][j] == 0) {
						rows.push_back(i);
						cols.push_back(j);
					}
				}
			}			
		
			for (auto r:rows) {
				for (auto i=0; i<n; ++i) {
					matrix[r][i] = 0;
				}
			}	
			
			for (auto c:cols) {
				for (auto i=0; i<m; ++i) {
					matrix[i][c] = 0;
				}
			}	
    }
};

void print(const vector<vector<int>> &matrix)
{
	for (const auto &vi : matrix) {
		for (auto i: vi) {
			cout << i << " ";
		}
		cout << endl;
	}
	cout << "--" << endl;
}
	
int main()
{
	Solution s;
	vector<vector<int>> matrix{{1,1,1},{1,0,1},{1,1,1}};
	print(matrix);
	s.setZeroes(matrix);
	print(matrix);
	return 0;
}
