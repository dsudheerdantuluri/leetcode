#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
		bool isOperator(const string &op) {
				return (op == "+") ||
							 (op == "-") ||
							 (op == "*") ||
							 (op == "/");
		}

		int performOp(int a, int b, string op) {
				if (op == "+" ) return a+b;
				if (op == "-" ) return a-b;
				if (op == "*" ) return a*b;
				if (op == "/" ) return a/b;
				return 0;
		}	

public:
    int evalRPN(vector<string>& tokens) {
			stack<int> s;
			for (const auto &token : tokens) {
				if (!isOperator(token)) s.push(stoi(token));
				else {
					auto op1 = s.top(); s.pop();			        
					auto op2 = s.top(); s.pop();
					auto op = performOp(op2, op1, token);
					s.push(op);
				}
			}
			return s.top(); 
    }
};

int main()
{
	return 0;
}
