#include <iostream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

			auto v1_startpos = 0;
			auto v2_startpos = 0;

			while ( (v1_startpos != string::npos) || (v2_startpos != string::npos) ) {

				auto v1_dotpos = version1.find(".", v1_startpos);
				auto v2_dotpos = version2.find(".", v2_startpos);

				auto v1_part1_len = (v1_dotpos != string::npos) ? (v1_dotpos - v1_startpos) : string::npos;
				auto v2_part2_len = (v2_dotpos != string::npos) ? (v2_dotpos - v2_startpos) : string::npos;

				auto v1_part1 = (v1_startpos != string::npos) ? stoi(version1.substr(v1_startpos, v1_part1_len)) : 0;
				auto v2_part1 = (v2_startpos != string::npos) ? stoi(version2.substr(v2_startpos, v2_part2_len)) : 0;
			
				if ( v1_part1 > v2_part1 ) return 1;
				else if ( v2_part1 > v1_part1 ) return -1;

			  v1_startpos = (v1_dotpos != string::npos) ? v1_dotpos + 1 : string::npos;	
			  v2_startpos = (v2_dotpos != string::npos) ? v2_dotpos + 1 : string::npos;	

			}

			return 0;	
    }
};

int main()
{
	Solution s;
	cout << s.compareVersion("1", "1.1") << endl;
	return 0;
}
