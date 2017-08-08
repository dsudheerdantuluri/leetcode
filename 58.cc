#include <iostream>

using namespace std;

class Solution {

	public:
    int lengthOfLastWord(string s) {
			 auto lwe = s.find_last_not_of(' ');
			 auto pos = s.find_last_of(' ', lwe);
			 auto lwb = (pos == string::npos) ? 0 : pos+1; 
       return lwe == string::npos ? 0 : lwe-lwb+1;
    }
};


int main()
{
	Solution s;
	cout << s.lengthOfLastWord("Hello World") << endl;
	cout << s.lengthOfLastWord("a ") << endl;
	cout << s.lengthOfLastWord("sudheer") << endl;
	cout << s.lengthOfLastWord("   ") << endl;
	return 0;
}
