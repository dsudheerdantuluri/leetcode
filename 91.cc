#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s)  
    {
			if ( s.length() == 0 ) return 0;

			vector<int> nd(s.length(), 0);

			nd[0] = (s[0] == '0') ? 0 : 1;

			for ( int i = 1; i < s.length(); ++i ) {
				int num = stoi(s.substr(i-1, 2));
				if ( s[i] == '0' ) {
					if ( num >= 10 && num <= 26 ) {
						nd[i] =  (i >= 2) ? nd[i-2] : 1;
					} else {
						nd[i] = 0;
					}
				} else {
					if ( num >= 10 && num <= 26 ) {
						nd[i] = nd[i-1] + ((i>=2) ? nd[i-2] : 1);
					} else {
						nd[i] = nd[i-1];
					}	
				}
			}
				
			return nd[s.length()-1]; 
    }   
};

int main()
{
	Solution s;	
	cout << s.numDecodings("0") << endl;
	cout << s.numDecodings("12") << endl;
	cout << s.numDecodings("10") << endl;
	cout << s.numDecodings("01") << endl;
	cout << s.numDecodings("1168963884134125126536966946586868418993819971673459188478711546479621135253876271366851168524933185") << endl;
	return 0;
}
