// https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs

#include <bits/stdc++.h>

using namespace std;

static const int INF = 1e8;

int main() {

	int q;
	cin >> q;

	while (q--) {
		int n, m, s;
		cin >> n >> m;
		vector<pair<int, int>> adj[n+1];
		vector<int> visited(n+1, 0);
		vector<int> distance(n+1, INF);
		for (int i = 0; i < m; i++) {
			int f, t;
			cin >> f >> t;
			adj[f].push_back({t, 6});
			adj[t].push_back({f, 6});
		}
		cin >> s;
		
		queue<pair<int, int>> q;

		distance[s] = 0;
		q.push({0, s});
		while (!q.empty()) {
			int a = q.front().second; q.pop();
			if (visited[a]) continue;
			visited[a] = true;
			for (auto u : adj[a]) {
				int b = u.first, w = u.second;
				if (distance[a] + w < distance[b]) {
					distance[b] = distance[a] + w;
					q.push({-distance[b], b});
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (i == s) continue;

			if (distance[i] == INF)
				cout << "-1";
			else
				cout << distance[i];

			if (i != n) cout << " ";
		}
		cout << "\n";



	}


	return 0;
}