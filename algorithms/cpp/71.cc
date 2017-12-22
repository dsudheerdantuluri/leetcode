#include <iostream>
#include <list>
#include <algorithm>
#include <regex>

using namespace std;

class Solution {
	public:
		string simplifyPath(string path) 
		{
			regex pat("(/+)");
			path = regex_replace (path,pat,"/");

			string result(path.substr(0,1));

			list<string> tokens;
			
			auto tb = 1;
			while ( tb != string::npos ) {
				auto te = path.find_first_of("/", tb);
				auto tkn = path.substr(tb, te-tb);
				//cout << "tkn:" << tkn << endl;
				if ( tkn == ".." ) {
					if (tokens.size()) tokens.pop_back();
				} else if ( tkn != "." ) {
					tokens.push_back(tkn);
				}
				tb = path.find_first_not_of("/", te);
			}
		
			for_each(tokens.begin(), tokens.end(), 
       [&result](const string &tkn) { result += tkn + "/"; });
		
			if (tokens.size() && result.length() && result[result.length()-1]=='/')
				result.erase(result.length()-1);
			
			return result;
		}
};

int main()
{
	Solution s;
	cout << s.simplifyPath("/home/") << endl;
	cout << s.simplifyPath("/a/./b/../../c/") << endl;
	cout << s.simplifyPath("/../") << endl;
	cout << s.simplifyPath("/home//foo") << endl;
	cout << s.simplifyPath("/") << endl;
	cout << s.simplifyPath("///TJbrd/owxdG//") << endl;
	cout << s.simplifyPath("/.///NWtm/KBp/TQdj/a/v/rsJ/n/j/../../lsw/./j/../Gh/////gNBxM/./") << endl;
	return 0;
}
