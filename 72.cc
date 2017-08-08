#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) 
		{
			auto m = word1.length();
			auto n = word2.length();

			vector<vector<int>> ed(m+1, vector<int>(n+1, 0));

			ed[0][0] = 0;

			for (auto i=0; i<=m; ++i)
				ed[i][0] = i;
	
			for (auto i=0; i<=n; ++i)
				ed[0][i] = i;
		
			for (auto i=1; i<=m; ++i) {
				for (auto j=1; j<=n; ++j) {
					if (word1[i-1] == word2[j-1]) {
						ed[i][j] = ed[i-1][j-1];
					} else {
            ed[i][j] = min(min(ed[i-1][j-1]+1/*replace*/, ed[i-1][j]+1/*delete*/),
                           ed[i][j-1]+1/*insert*/);
					}
				}
			}

			return ed[m][n];	
    }
};


int main()
{
	Solution s;
	cout << s.minDistance("sudheer", "dileep") << endl;
	return 0;
}
