#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n, cnt = 0;
	cin >> n;
	map<int, int> m;

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		m[x]++;
		if (m[x] % 2 == 0)
			cnt++;
	}

	cout << cnt << "\n";

	return 0;
}