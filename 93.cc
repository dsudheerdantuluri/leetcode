#include <iostream>
#include <vector>

using namespace std;

class Solution {
	private:
		void restoreIpAddressesImpl(string s, string ws, int numDots, vector<string> &result, int l)
		{
			if (numDots == 3) {
				auto num = stoi(s);
				if ( num >= 0 && num <= 255 ) {
					ws += to_string(num);
					if (ws.length() == 3+l) { 	
						result.emplace_back(ws);
					}
				}
				return;
			}
			
			for (int i=1; i<=3; ++i) {
				if (s.length() <= i) continue;
				auto comp = s.substr(0, i);
				auto cn = stoi(comp);
				if (cn >= 0 && cn <= 255) restoreIpAddressesImpl(s.substr(i, string::npos), ws + to_string(cn) + ".", numDots+1, result, l);
			}
		}

	public:
    vector<string> restoreIpAddresses(string s) 
		{
			vector<string> result;

			if (s.length() > 12) return result;

			string empty("");

			restoreIpAddressesImpl(s, empty, 0, result, s.length());

			return result;
    }
};

int main()
{
	Solution s;
	//vector<string> ips = s.restoreIpAddresses("25525511135");
	//vector<string> ips = s.restoreIpAddresses("0000");
	vector<string> ips = s.restoreIpAddresses("010010");
	for (auto ip : ips) {
		cout << ip << endl; 
	}
	return 0;
}
