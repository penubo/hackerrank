// https://www.hackerrank.com/challenges/jumping-on-the-clouds/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>

using namespace std;

int main()
{

	int n;

	cin >> n;
	vector<int> arr(n + 1);
	vector<int> dp(n + 1, INT32_MAX);
	dp[0] = 0;
	dp[1] = 0;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 2; i <= n; i++)
	{
		if (arr[i])
			continue;
		dp[i] = min(dp[i - 1], dp[i - 2]) + 1;
	}
	cout << dp[n] << "\n";

	return 0;
}