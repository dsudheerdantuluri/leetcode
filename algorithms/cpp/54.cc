#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
		{
			vector<int> result;

			if (matrix.size() == 0) {
				return result;
			}

			int rb = 0, cb = 0, re = matrix.size() - 1, ce = matrix[0].size() - 1;
       
			int r = rb, c = cb;

			while (rb <= re && cb <= ce) {

				for ( r=rb, c=cb; c <= ce ; ++c )
					result.emplace_back(matrix[r][c]);	
	
				for ( r=rb+1, c=ce; r <= re ; ++r )
					result.emplace_back(matrix[r][c]);

				for ( r=re, c=ce-1; re>rb &&  c>=cb ; --c )
					result.emplace_back(matrix[r][c]);	

				for ( r=re-1, c=cb; r > rb && cb<ce ; --r )
					result.emplace_back(matrix[r][c]);
				
				rb++;
				ce--;
				re--;
				cb++;
			
			}

			return result;
    }
};

int main()
{
	Solution s;
	vector<vector<int>> v1{{1,2,3},{4,5,6},{7,8,9}};
	for (auto i: s.spiralOrder(v1)) {
		cout << i << " ";
	}	
	cout << endl;

	vector<vector<int>> v2{{2,5,8},{4, 0, -1}};
	for (auto i: s.spiralOrder(v2)) {
		cout << i << " ";
	}	
	cout << endl;

	vector<vector<int>> v3{{3},{2}};
	for (auto i: s.spiralOrder(v3)) {
		cout << i << " ";
	}	
	cout << endl;
	
	vector<vector<int>> v4{{1}};
	for (auto i: s.spiralOrder(v4)) {
		cout << i << " ";
	}	
	cout << endl;
	
	vector<vector<int>> v5{{2,3}};
	for (auto i: s.spiralOrder(v5)) {
		cout << i << " ";
	}	
	cout << endl;
	
	vector<vector<int>> v6{{7},{9}, {6}};
	for (auto i: s.spiralOrder(v6)) {
		cout << i << " ";
	}	
	cout << endl;
	
	return 0;
}
