#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
			
			using vvs = vector<vector<string>>;
			using vs = vector<string>;
			
			map<string, vs> msvs;

			for (const auto &s : strs) {
				string ss(s);
				sort(ss.begin(),ss.end());
				msvs[ss].emplace_back(s);
			}
			
			vvs result;
			for (const auto &s : msvs) {
				result.emplace_back(s.second);
			}

			return result;		
			        
    }
};


int main()
{
	Solution s;
	vector<string> vs{"eat", "tea", "tan", "ate", "nat", "bat"};
	auto vvs = s.groupAnagrams(vs);
	for (auto &vs : vvs) {
		for (auto &s : vs) {
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}
