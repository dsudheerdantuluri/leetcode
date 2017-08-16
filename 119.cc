#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
	public:
    vector<int> getRow(int rowIndex) 
		{
    	vector<int> result(rowIndex + 1, 1);

			for (auto row = 0; row <= rowIndex; ++row) {
				for (auto col = row-1; col > 0; --col) {
					result[col] += result[col-1];
				}
			}

			return result; 
    }
};

int main()
{
	return 0;
}
