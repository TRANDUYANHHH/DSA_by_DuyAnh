// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif
const int maxN = 105;
int g[maxN][maxN][4];
int sh[maxN][maxN];
bool vis[maxN][maxN];
int cnt;
const	int dx[] = {-1, 0, 0, 1};
const	int dy[] = {0, -1, 1, 0};
int n, kk, m;

void prepare() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			vis[i][j] = false;
		}
	}
}

void dfs(int i, int j) {
	if(sh[i][j] != 0) {
		cnt++;
	}
	vis[i][j] = true;
	for(int k = 0; k < 4; k++) {
		if(!g[i][j][k]) {
			int ni = i + dx[k];
			int nj = j + dy[k];
			if(ni >= 1 && ni <= n && nj >= 1 && nj <= n && !vis[ni][nj]) {
				dfs(ni, nj);
			}
		}
	}
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	cin >> n >> kk >> m;
	for(int i = 0; i < m; i++) {
		int u, v, x, y;
		cin >> u >> v >> x >> y;
		for(int k = 0; k < 4; k++) {
			if(u + dx[k] == x && v + dy[k] == y) {
				g[u][v][k] = 1;
				break;
			}
		}
		for(int k = 0; k < 4; k++) {
			if(x + dx[k] == u && y + dy[k] == v) {
				g[x][y][k] = 1;
				break;
			}
		}
	}
	for(int i = 0; i < kk; i++) {
		int u, v;
		cin >> u >> v;
		sh[u][v] = i + 1;
	}
	int cc = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(sh[i][j] != 0) {
				prepare();
				cnt = 0;
				dfs(i, j);
				cc += (cnt - 1);
			}
		}
	}
	cout << kk * (kk - 1) / 2 - (cc / 2);
  return 0;  
}
