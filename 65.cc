#include <iostream>

using namespace std;

class Solution {
	private:
		bool isDigit(char d) { return (d>='0' && d<='9'); }

	public:
		bool isNumber(string s) 
		{
			auto i = 0;
			bool digit = false;

			while (i<s.length() && s[i]==' ') ++i;

			if (i<s.length() && (s[i]=='+' || s[i]=='-')) ++i;

			while (i<s.length() && isDigit(s[i])) {
				digit = true;
				++i;
			}

			if (i<s.length() && s[i] == '.' && (isDigit(s[i-1]) || (i+1<s.length() && (isDigit(s[i+1]) || s[i+1]=='e')))) {
				++i;
				while (i<s.length() && isDigit(s[i])) {
					digit = true;
					++i;
				}
			}

			if (i<s.length() && s[i] == 'e' && (isDigit(s[i-1]) || (s[i-1] == '.' && digit)) && i+1<s.length() && (isDigit(s[i+1]) || s[i+1]=='+' || s[i+1]=='-')) {
				++i;
				if(s[i]=='+' || s[i]=='-') {
					++i;
					digit = false;
				}
				while (i<s.length() && isDigit(s[i])) {
					digit = true;
					++i;
				}
			}

			while (i<s.length() && s[i]==' ') ++i;

			return digit && (i == s.length());
		}
};

int main()
{
	Solution s;
	cout << "0:" << s.isNumber("0") << endl;
	cout << " 0.1 :" << s.isNumber(" 0.1 ") << endl;
	cout << "abc:" << s.isNumber("abc") << endl;
	cout << "1 a:" << s.isNumber("1 a") << endl;
	cout << "2e10:" << s.isNumber("2e10") << endl;
	cout << "e:" << s.isNumber("e") << endl;
	cout << ".:" << s.isNumber(".") << endl;
	cout << " :" << s.isNumber(" ") << endl;
	cout << ".1:" << s.isNumber(".1") << endl;
	cout << "46.e3:" << s.isNumber("46.e3") << endl;
	cout << "e9:" << s.isNumber("e9") << endl;
	cout << ".e1:" << s.isNumber(".e1") << endl;
	cout << "005047e+6:" << s.isNumber("005047e+6") << endl;
	cout << "4e+:" << s.isNumber("4e+") << endl;
	return 0;
}
