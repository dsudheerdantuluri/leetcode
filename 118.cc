#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
	public:
    vector<vector<int>> generate(int numRows) 
		{
			vector<vector<int>> result(numRows);
			
			for (auto row = 0; row < numRows; ++row) {
				vector<int> rowVec(row+1, 1);
				for (auto col = 1; col < row; ++col) {
					rowVec[col] = result[row-1][col] + 
                        result[row-1][col-1];
				}
				result[row] = rowVec;  
			}
     
			return result; 
    }
};

int main()
{
	return 0;
}
