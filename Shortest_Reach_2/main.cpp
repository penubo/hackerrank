// https://www.hackerrank.com/challenges/dijkstrashortreach/problem?h_r=internal-search

#include <vector>
#include <iostream>
#include <queue>


using namespace std;

#define INF 10000000000000

void solution() {
	int n, m, x, y, w, s;
	priority_queue<pair<int, int>> q;

	cin >> n >> m;

	vector<pair<int, int>> adj[n+1];
	bool visited[n+1];
	long long distance[n+1];


	for (int i = 1; i <= n; i++) {
		visited[i] = false;
		distance[i] = INF;
	}
		
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> w;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	cin >> s;

	distance[s] = 0;
	q.push({0, s});

	while (!q.empty()) {
		int a = q.top().second; q.pop();
		if (visited[a]) continue;
		visited[a] = true;
		for (auto u : adj[a]) {
			int b = u.first;
			int ww = u.second;
			if (distance[a] + ww < distance[b]) {
				distance[b] = distance[a] + ww;
				q.push({-distance[b], b});
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i == s)
			continue;
		else if (distance[i] != INF)
			cout << distance[i] << " ";
		else
			cout << -1 << " ";
	}

}


int main() {
	
	int t;

	cin >> t;

	while (t--) {
		solution();
		cout << "\n";
	}


	return 0;
}