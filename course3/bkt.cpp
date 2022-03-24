#include <fstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
ifstream in("main.in");
ofstream out("main.out");

// BACKTRACKING STANDARD

int sol[20], max_val = 9, n;
int ce_caut[20];

void init(int k)
{
	sol[k] = 0;
}
bool succesor(int k)
{
	// verif daca putem obtine urm val
	if (sol[k] < max_val) {
		// obtinem urmatoarea valoare din multime
		sol[k]++;
		return 1;
	}
	return 0;
}

bool valid(int k)
{
	if (sol[k - 1] == sol[k])
		return 0;
	return 1;
}
bool solutie(int k)
{
	if (k == n)
	{
		for (int i = 1; i <= n; i++)
			if (sol[i] != ce_caut[i])
				return 0;
		return 1;
	}
	else
		return 0;
}

void print()
{
	for (int i = 1; i <= n; i++) out << sol[i] << ' ';
	out << '\n';
}

void bkt_permutari()
{
	int k = 1, isSuc, isValid;
	init(k);
	while (k > 0)
	{
		isSuc = isValid = 0;
		if (k <= n)
		{
			do
			{
				isSuc = succesor(k);
				if (isSuc)
					isValid = valid(k);
			} while (isSuc && !isValid);

		}

		if (isSuc) // succesor & valid
		{
			if (solutie(k))
			{
				print();
				return;
			}
			else
				k++, init(k);
		}
		else
			k--;
	}
}

int main()
{
	sol[0] = -1;
	in >> n;
	for (int i = 1; i <= n; i++)
		in >> ce_caut[i];
	bkt_permutari();
}
