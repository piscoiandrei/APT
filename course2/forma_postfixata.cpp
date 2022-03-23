#include <fstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
ifstream in("main.in");
ofstream out("main.out");


int prio(char c)
{
	if (strchr("*/", c))
		return 1;
	if (strchr("+-", c))
		return 2;
	return -1;
}
bool isOperand(char c)
{
	return isalnum(c);
}
void postfixForm(char s[])
{
	// assuming correct input
	deque<char> op;

	int countp = 0;
	for (int i = 0; s[i]; i++)
	{
		if (isOperand(s[i]))
			out << s[i];
		if (prio(s[i]) == 1)
			op.push_back(s[i]);
		else
			if (prio(s[i]) == 2)
			{
				while (!op.empty() && prio(op.back()) == 1)
				{
					out << op.back();
					op.pop_back();
				}
				op.push_back(s[i]);
			}
			else
				if (s[i] == '(')
					op.push_back('(');
				else
					if (s[i] == ')')
					{
						while (!op.empty() && op.back() != '(')
						{
							if (op.back() != '(')
								out << op.back();
							op.pop_back();
						}
						op.pop_back();
					}
	}
	while (!op.empty())
	{
		if(op.front() != '(')
			out << op.front();
		op.pop_front();
	}
}

int main()
{
	char input[100];
	in >> input;
	postfixForm(input);
}
