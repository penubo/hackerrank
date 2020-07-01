// https://www.hackerrank.com/challenges/counting-valleys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n;
	cin >> n;
	int prev = 0, curr = 0, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		char c;
		cin >> c;
		if (c == 'U')
		{
			curr++;
		}
		else
		{
			curr--;
		}
		if (prev < 0 && curr == 0)
			cnt++;
		prev = curr;
	}
	cout << cnt << "\n";

	return 0;
}