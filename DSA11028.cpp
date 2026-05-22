// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

const int  maxN = 1e5 + 5;
vector<int> g[maxN];
int ans = 0;

void dfs(int u, int pre, int d) {
	ans = max(ans, d);
	for(int v : g[u]) {
		if(v != pre) {
			dfs(v, u, d + 1);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		g[i].clear();
	}
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans = 0;
	dfs(1, 1, 0);
	cout << ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		solve();
		cout << '\n';
	}	
  return 0;  
}
