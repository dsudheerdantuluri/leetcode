#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
			return findKthLargest(nums, 0, nums.size() - 1, k);       
    }
    int findKthLargest(vector<int>& nums, int l, int h, int k) {
			//cout << "l:" << l << " h:" << h << " k:" << k << endl;
			//std::srand(std::time(0));
			//int randPos = l + std::rand() % (h - l + 1);
			int randPos = h - l;
			cout << "randPos:" << randPos << endl;
			int randElem = nums[l + randPos];
			cout << "randElem:" << randElem << endl;
			auto f = [randElem] (int i) { return i > randElem; };
			auto it = partition(nums.begin() + l, nums.begin() + h, f);
			int pos = (it - (nums.begin() + l));
			cout << "pos:" << pos << endl;
			if ((pos+1) == k) return randElem;
			else if ((pos+1) > k) return findKthLargest(nums, l, pos-1, k);	
			else return findKthLargest(nums, pos+1, h, k-pos-1); 
		}
};
int main() { 
vector<int> v{-1,2,0};
Solution s;
cout << s.findKthLargest(v, 3) << endl;
return 0;
}
