// lt30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) 
	{
		vector<int> result;
		
		unsigned int k = words.size();
		if (k == 0) {
			return result;
		}

		unsigned int wl = words[0].length();
		
		unordered_map<string, int> wm, g;		
		for (auto w : words) {
			wm.emplace(w, 0);
			g.emplace(w, 0);
		}

		for (auto w : words) {
			g[w]++;
		}		
		
		for (auto i = 0; i < s.length(); ++i) {
			for (auto j = i; j < i+k*wl; j += wl) {
				std::string w1 = s.substr(j, wl);
				auto it = wm.find(w1);
				if (it != wm.end()) {
					++it->second;
				} else {
					break;
				}
			}
			bool am = true;
			for (auto w3 : wm) {
				if ((wm[w3.first] != g[w3.first])) {
					am = false;
					break;
				}
			}
			/*cout << "------------------------------------" << endl;
			cout << "i:" << i << endl;
			for (auto w4 : wm) {
				cout << w4.first.c_str() << " " << w4.second << endl;
			}
			cout << "------------------------------------" << endl;*/
			if (am) {
				result.emplace_back(i);
			}
			for (auto w3 : wm) {
				wm[w3.first] = 0;
			}
		}

	/*	for (auto i = 0; i < s.length(); ++i) {
		
			std::string w1 = s.substr(i, wl);
			auto it = wm.find(w1);
			if (it != wm.end()) {
				++it->second;				
			}

			if ( i >= (k-1)*wl+1 ) {
				std::string w2 = s.substr(i-(k-1)*wl-1, wl);
				auto it = wm.find(w2);
				if (it != wm.end()) {
					--it->second;					
				}			
			}

			bool am = true;
			if (i >= (k - 1)*wl) {
				bool allMatch = true;
				for (auto w3 : words ) {
					if ( (wm.find(w3) != wm.end()) && (wm[w3] != g[w3]) ) {
						am = false;
						break;
					}
				}
 				if (am) {
					result.emplace_back(i - (k-1)*wl);
				}
			}

			cout << "------------------------------------" << endl;
			cout << "i:" << i << endl;
			for (auto w4 : wm) {
				cout << w4.first.c_str() << " " << w4.second << endl;
			}
			cout << "------------------------------------" << endl;						
			
		}
*/
		return result;

	}
};

int main()
{
	Solution s;
	vector<string> words({ "fooo","barr","wing","ding","wing" });
	auto vi = s.findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", words);
	for (auto i : vi) {
		cout << i << " ";
	}
	cout << endl;

	/*vector<string> words({ "foo", "bar" });
	auto vi = s.findSubstring("barfoothefoobarman", words);
	for (auto i : vi) {
		cout << i << " ";
	}
	cout << endl;*/


	//vector<string> words({ "aa","aa","aa" });
	//auto vi = s.findSubstring("aaaaaaaa", words);
	//for (auto i : vi) {
	//cout << i << " ";
	//}
	//cout << endl;

    return 0;
}

