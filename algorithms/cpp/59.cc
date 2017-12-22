#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
		{
			vector<vector<int>> result(n, vector<int>(n, 0));

			int rb = 0, re = n-1, cb = 0, ce = n-1, val = 0;

			while (rb<=re && cb<=ce) {

				for (int r=rb, c=cb; c <= ce; ++c)
					result[r][c] = ++val;

				for (int r=rb+1, c=ce; r <= re; ++r)
					result[r][c] = ++val;

				if (re>rb) {
					for (int r=re, c=ce-1; c >= cb; --c)
						result[r][c] = ++val;
				}

				if (ce>cb) {
					for (int r=re-1, c=cb; r > rb; --r)
						result[r][c] = ++val;
				}

				rb++,cb++,re--,ce--;
			}
		
			return result;
        
    }
};

int main()
{
	Solution s;
	for (const auto &vi: s.generateMatrix(3)) {
		for (auto i : vi) {
			cout << i << " ";
		}
		cout << endl;
	}

	return 0;
}
