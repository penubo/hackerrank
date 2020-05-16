#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100010];
bool visited[100010];

void dfs(int i, int *cnt) {
	if (visited[i])
		return;
	visited[i] = true;
	*cnt += 1;
	for (int n : adj[i]) {
		if (!visited[n]) {
			dfs(n, cnt);
		}
	}
}

long long cc_load_cnt(int n, int m, int cl, int cr) {
	long long res = 0;
	int cnt = 0;
	int t, f;

	for (int i = 0; i < m; i++) {
		cin >> t >> f;
		adj[t].push_back(f);
		adj[f].push_back(t);
	}

	for (int i = 1; i <= n; i++) {
		cnt = 0;
		if (!visited[i]) {
			dfs(i, &cnt);
			res += cl + (cnt - 1) * min(cr, cl);
		}
	}
	return res;
}

int main() {

	int q;
	int n, m, cl, cr;

	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> n >> m >> cl >> cr;
		for (int j = 0; j < 100001; j++) {
			adj[j].clear();
			visited[j] = false;
		}
		long long res = cc_load_cnt(n, m, cl, cr);
		cout << res  << "\n";
	}

	return 0;
}