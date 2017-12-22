#include <iostream>
#include <stack>

using namespace std;

class MinStack {

	struct stackNode {
		int val;
		int min;
	};

  using stackNode = struct stackNode;

	stack<stackNode> m_s;
	
public:
    /** initialize your data structure here. */
    MinStack() {
    	 
    }
    
    void push(int x) {
    	stackNode sn{x,x};
			if (!m_s.empty()) {
				stackNode top = m_s.top();
				sn.min = min(sn.min, top.min);
			} 
			m_s.push(sn);
    }
    
    void pop() {
    	m_s.pop(); 
    }
    
    int top() {
     stackNode sn = m_s.top();
		 return sn.val;   
    }
    
    int getMin() {
     stackNode sn = m_s.top();
		 return sn.min;   
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main()
{
	return 0;
}
