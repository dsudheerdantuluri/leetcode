#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) 
    {
			vector<vector<int>> table(s.length() + 1, vector<int>(t.length() + 1, 1));

			for (auto j = 1; j <= t.length(); ++j ) table[0][j] = 0;

			for (auto i = 1; i <= s.length(); ++i ) {
				for (auto j = 1; j <= t.length(); ++j ) {
					if ( s[i-1] == t[j-1] ) {
						table[i][j] = table[i-1][j] + table[i-1][j-1];
					} else {
						table[i][j] = table[i-1][j];
					}
				}
			}

			return table[s.length()][t.length()];	 
    }
};

int main()
{
	return 0;
}
