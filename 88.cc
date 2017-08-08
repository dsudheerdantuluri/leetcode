#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
		{
			int i = m-1, j = n-1, k = m+n-1;
      if (nums1.size() != 0 && nums2.size() == 0) return;
      if (nums1.size() == 0 && nums2.size() != 0) {
      	nums1 = nums2;
        return;
			}
			while ( k >= 0 ) {
				if (i<0) nums1[k--] = nums2[j--];
        else if (j<0) nums1[k--] = nums1[i--];
        else nums1[k--] = (nums1[i] >= nums2[j]) ? nums1[i--] : nums2[j--];
			}
    }
};

int main()
{
  Solution s;
  vector<int> nums1{2, 3};	
  vector<int> nums2{1, 4};
  s.merge(nums1, nums1.size(), nums2, nums2.size());
  for (unsigned i = 0; i < nums1.size() + nums2.size(); ++i )
		cout << nums1[i] << " ";
  cout << endl;
  //auto print = [](int i) { cout << i << " "; };
  //for_each(nums1.begin(), nums1.end(), print);	
  //cout << endl;
	return 0;
}
