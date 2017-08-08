#include <iostream>
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;

class Solution 
{
	public:
    bool isInterleave(string s1, string s2, string s3) 
		{
			if ( s1.length() + s2.length() != s3.length() ) return false;

			vector<bool> il(s2.length()+1, false);

			for (int i=0; i <= s1.length(); ++i) {
				for (int j=0; j <= s2.length(); ++j) {
					if ( (i==0) && (j==0) ) {
						il[j] = true;
					} else if ( i==0 ) {
						il[j] = il[j-1] && (s2[j-1] == s3[i+j-1]);
					} else if ( j==0 ) {
						il[j] = il[j] && (s1[i-1] == s3[i+j-1]);
					} else {
						il[j] = (il[j] && s1[i-1] == s3[i+j-1]) || (il[j-1] && (s2[j-1] == s3[i+j-1]));
					}
				}
			}

			return il[s2.length()]; 
    }
};

int main()
{
	auto t0 = high_resolution_clock::now();
	Solution s;
	cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
	cout << s.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
	cout << s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa",
                         "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab",
                         "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab") << endl;
	auto t1 = high_resolution_clock::now();
	cout << duration_cast<milliseconds>(t1-t0).count() << endl;
	return 0;
}
