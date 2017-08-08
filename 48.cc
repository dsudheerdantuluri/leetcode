#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
			if (!matrix.size()) 
				return;
			
			auto i = 0;
			auto j = matrix.size()-1;
      	
			while (i<j) {
				auto p = matrix.size()-1;
				for (auto k=i; k<j; ++k) {
					auto temp = matrix[i][k];
					matrix[i][k] = matrix[p-k][i];//1,1 : 1,1
					matrix[p-k][i] = matrix[p-i][p-k];
					matrix[p-i][p-k] = matrix[k][p-i];
					matrix[k][p-i] = temp;
				}
				++i; --j;
			}
    }
};

int main()
{
	Solution s;
	//vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
	s.rotate(matrix);
	for (auto &vi:matrix) {
		for (auto i:vi) {
			cout << i << " ";
		} 
		cout << endl;
	}
	return 0;
}
