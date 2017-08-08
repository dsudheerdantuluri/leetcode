#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	public:
		void myreplace(string &parent, const string &src, const string &rep)
		{
			std::string::size_type n = 0;
			while ( ( n = parent.find( src, n ) ) != std::string::npos )
			{
				parent.replace( n, src.size(), rep );
				n += rep.size();
			}
		}

		vector<string> fullJustify(vector<string>& words, int maxWidth) 
		{
			vector<string> result;

			string s("");	
			for (const auto &str : words) {
				if (s.length() + str.length() > maxWidth) {
					if (s[s.length()-1] == ' ') 
						s.pop_back();
					result.emplace_back(s);
					s="";
				}
				s += str;
				if (s.length() < maxWidth) {
					s += " ";
				}
			}

			if (s[s.length()-1] == ' ') 
				s.pop_back();
			result.emplace_back(s);

			for (auto i = 0; i < result.size() ; ++i) {
				auto &str = result[i];
				auto numSpaces = count_if(str.begin(), str.end(), [](char c) { return c==' '; });
				auto slack = maxWidth - str.length();
				if (numSpaces> 0 && (i != result.size()-1)) {
					myreplace(str, " ", string(slack/numSpaces + 1,' '));
					auto pos = 0;	
					for ( auto k = 1; k <= slack%numSpaces; ++k) {
						pos = str.find_first_of(" ", pos);
						str.replace(pos, 1, "  ");
						pos = str.find_first_not_of(" ", pos);
					}
				} else {
					str += string(slack, ' ');
				}	
			}

			return result; 
		}
};

int main()
{
	Solution s;
	vector<string> i1{"This", "is", "an", "example", "of", "text", "justification."};
	for (const auto &str : s.fullJustify(i1,16)) {
		cout << str << ";" << endl;
	}
	vector<string> i2{"What", "must", "be", "shall", "be"};
	for (const auto &str : s.fullJustify(i2,12)) {
		cout << str << ";" << endl;
	}
	vector<string> i3{"Listen", "to", "many,", "speak", "to", "a", "few."};
	for (const auto &str : s.fullJustify(i3,6)) {
		cout << str << ";" << endl;
	}
	return 0;
}
