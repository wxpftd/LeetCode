#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int evalRPN(vector<string> &tokens)
{
	vector<int> stack;
	int front = 0, back = 0;
	for (string c: tokens)
	{
		char op;
		int strsize = strlen(c.c_str());
		if (strsize == 1)
			op = c.c_str()[0];
		else
			op = 0;

		switch (op)
		{
			case '+':
				back = stack.back();
				stack.pop_back();
				front = stack.back();
				stack.pop_back();
				stack.push_back(back + front);
				break;
			case '-':
				back = stack.back();
				stack.pop_back();
				front = stack.back();
				stack.pop_back();
				stack.push_back(front - back);
				break;
			case '*':
				back = stack.back();
				stack.pop_back();
				front = stack.back();
				stack.pop_back();
				stack.push_back(front * back);
				break;
			case '/':
				back = stack.back();
				stack.pop_back();
				front = stack.back();
				stack.pop_back();
				stack.push_back(front / back);
				break;
			default:
				stack.push_back(atoi(c.c_str()));
		}
	}
	return stack.back();
}

int main()
{
	vector<string> tokens{"4", "-13", "5", "/", "+"};
	cout << evalRPN(tokens) << endl;
	return 0;
}

