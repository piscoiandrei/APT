#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
ifstream in("main.in");
ofstream out("main.out");

int sol[20], n, found;


void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (sol[i] == j)
				cout << "* ";
			else
				cout << "- ";
		cout << '\n';
	}
}

int solution(int k)
{
	return k == n;
}

bool valid(int k)
{
	// convention: index = line, sol[index] = column
	for (int a = 1; a < k; a++)
	{
		if (k == a || sol[k] == sol[a])
			return 0;
		if (a + sol[a] == k + sol[k])
			return 0;
		if (a + sol[k] == k + sol[a])
			return 0;
	}
	return 1;

}
void back(int k)
{
	if (found)
		return;
	for (int i = 1; i <= n; i++)
	{
		sol[k] = i;
		if (valid(k))
		{
			if (solution(k))
				found = 1, print();
			else
				back(k + 1);
		}
	}
}

int main()
{
	cin >> n;
	back(1);
}
