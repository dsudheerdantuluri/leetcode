#include <iostream>

using namespace std;

class Solution {

	private:
		int mySqrt(int x, int low, int high)
		{
			auto mid = low + (high-low)/2;
			//cout << mid << endl;

			if ( (mid<=x/mid) && ((mid+1)>x/(mid+1)) ) {
				return mid;
			} else if (mid < x/mid) {
				return mySqrt(x, mid, high);
			} else {
				return mySqrt(x, low, mid);
			}
		}

	public:
    int mySqrt(int x) 
		{
			if (x==0) return 0;
		
			return mySqrt(x, 1, x);
    }
};

int main()
{
	Solution s;
	cout << s.mySqrt(2147395599) << endl; 
	cout << s.mySqrt(2) << endl; 
	cout << s.mySqrt(3) << endl; 
	cout << s.mySqrt(4) << endl; 
	cout << s.mySqrt(100) << endl; 
	cout << s.mySqrt(500) << endl; 
	cout << s.mySqrt(225) << endl; 
	cout << s.mySqrt(40000) << endl; 
	cout << s.mySqrt(91) << endl; 
	cout << s.mySqrt(10) << endl; 
	return 0;
}
