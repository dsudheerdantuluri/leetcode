#include <iostream>
#include <vector>

using namespace std;

template <typename ForwardIterator, typename Func>
void adjacent_pair(ForwardIterator first, ForwardIterator last, Func f)
{
    if (first != last)
    {
        ForwardIterator trailer = first;
        ++first;
        for (; first != last; ++first, ++trailer)
            f(*trailer, *first);
    }
}

class Solution 
{
	public:
    int maxProfit(vector<int>& prices) 
		{
			auto mp = 0;
			auto func = [&mp](int a, int b) { if (b>a) mp +=  b-a; };
			adjacent_pair(prices.begin(), prices.end(), func);
			return mp;
        
    }
};

int main()
{

	return 0;
}
