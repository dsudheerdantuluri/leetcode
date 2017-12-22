#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) 
		{
			auto start = s.find_first_not_of(" ");

			if (start == string::npos) s = "";
			else s = s.substr(start); 

			reverse(s.begin(), s.end());
			
			start = s.find_first_not_of(" ");

			if (start == string::npos) s = "";
			else s = s.substr(start);

			auto e = std::unique(s.begin(), s.end(), [](char l, char r){
        return std::isspace(l) && std::isspace(r) && l == r;
      });
			s = std::string(s.begin(), e);
 
			auto begin = s.find_first_not_of(" ");

			while (begin != string::npos) {

				auto end = s.find_first_of(" ", begin);

				reverse(s.begin() + begin, (end == string::npos) ? s.end() : s.begin() + end);

				begin = s.find_first_not_of(" ", end);
			}

    }
};

int main()
{
	Solution s;
	string str("  a    b ");
	s.reverseWords(str);
	cout << str << endl;
	return 0;
}
