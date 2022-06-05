#include <iostream>
#define N 10001
using namespace std;

int memo[N] = { 1, 1, };
int main()
{
	int n, m, sum = 0, min = 0;
	cin >> n >> m;

	for (int i = 2; i <= m; i++)
	{
		for (int j = i + i; j <= m && !memo[i]; j += i) memo[j] = 1;
	}
	for (int i = n; i <= m; i++)
	{
		if (!memo[i])
		{
			if (!min)
				min = i;
			sum += i;
		}
	}

	if (min)
		cout << sum << endl << min;
	else
		cout << -1;

	return 0;
}