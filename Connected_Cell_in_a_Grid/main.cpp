// https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>

using namespace std;

bool visited[12][12];
int matrix[12][12];
int offset[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int dfs(int x, int y) {
	int res = 1;
	if (visited[x][y])
		return 0;

	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + offset[i][0], ny = y + offset[i][1];
		if (matrix[nx][ny])
			res += dfs(nx, ny);
	}
	return res;
}

int main() {

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> matrix[i][j];
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && matrix[i][j]) {
				ans = max(ans, dfs(i, j));
			}
		}
	}

	cout << ans << "\n";


	return 0;
}