#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution 
{
	bool isPalindrome(const string &str)
	{
		int beg = 0;
		int end = str.length() - 1;

		while ( beg < end ) {
			if ( str[beg++] != str[end--] ) return false;
		}

		return true;
	}

	public:
    vector<vector<string>> partition(string s) 
		{
			vector<vector<string>> result;

		  vector<string> ans;

		  partitionImpl(s, 0, ans, result);

			return result;
		}

		void partitionImpl(string &s, int index, vector<string> &ans, vector<vector<string>> &result)
		{
			if (index == s.length()) {
				result.emplace_back(ans);
				return;
			}

			for (int i = index; i < s.length(); ++i) {
				string curr(s.substr(index, i-index+1));
				if (isPalindrome(curr)) {
					ans.emplace_back(curr);
					partitionImpl(s, i+1, ans, result);
					ans.pop_back();
				}
			}
		}

};

int main()
{
	Solution s;
	auto vvs = s.partition("cdd");
	for (auto vs : vvs) {
		for (auto s : vs) cout << s << " ";
			cout << endl;
	}
	return 0;
}
