// https://www.hackerrank.com/challenges/repeated-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>

using namespace std;

int main()
{

	string s;
	long long len, s_len = 0;

	cin >> s >> len;

	vector<int> acc;
	acc.push_back(0);
	for (char c : s)
	{
		if (c == 'a')
			acc.push_back(acc.back() + 1);
		else
			acc.push_back(acc.back());
		s_len++;
	}

	cout << len / s_len * acc[s_len] + acc[len % s_len] << "\n";

	return 0;
}