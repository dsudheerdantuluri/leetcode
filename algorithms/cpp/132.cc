#include<iostream>
#include<limits>
#include<vector>

using namespace std;

class Solution {
public:
	bool isPalindrome(const string &str)
	{
		int beg = 0;
		int end = str.length() - 1;

		while ( beg < end ) {
			if ( str[beg++] != str[end--] ) return false;
		}

		return true;
	}
  
	int minCut(string s) 
	{
		int n = s.length();

		vector<vector<bool>> pal(n, vector<bool>(n, false));

		vector<int> mc(n, 1);

		for (int i = 0; i < n; ++i ) {
			mc[i] = i;
			pal[i][i] = true;
		}

		for (int i = 0; i < n; ++i ) {
			auto m = i;
			for (int j = 0; j <= i; ++j ) {
				if ((s[i] == s[j]) && ( ((j+1) > (i-1)) || pal[j+1][i-1] )  ) {
					pal[j][i] = true;
					m = (j == 0) ? 0 : min(m, mc[j-1] + 1);
				}
			}
			mc[i] = m;
		}

    return mc[n-1];
	}
			
};

int main()
{
	Solution s;
	cout << s.minCut("aab") << endl;
	//cout << s.minCut("abbab") << endl;
	//cout << s.minCut("efe") << endl;
	//cout << s.minCut("cabababcbc") << endl;
	return 0;
}
