#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) 
		{
			int sum = 0;
			for (auto c: s) {
				sum = sum * 26 + (c - 'A' + 1);
			}	
      
			return sum;  
    }
};

int main()
{
	return 0;
}
