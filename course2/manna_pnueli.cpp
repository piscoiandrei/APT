#include <iostream>
#include <stack>
using namespace std;

int mannaPnueli(int x)
{
	stack<int> st;
	int last = -1;
	st.push(x);
	while (!st.empty())
	{
		int t = st.top();

		if (t < 12)
			st.push(t + 2);
		else
		{
			last = t - 1;
			if (!st.empty())
				st.pop();
			else
				break;
			if (!st.empty())
				st.pop();
			else
				break;
			st.push(last);
		}
	}
	return last;
}

int main()
{
	cout << mannaPnueli(6);
}
