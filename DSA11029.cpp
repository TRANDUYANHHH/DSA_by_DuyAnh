// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

const int maxN = 1005;
vector<int> g[maxN];
int par[maxN];
bool is_leaf[maxN];

void dfs(int u, int pre) {
	int child = 0;
	par[u] = pre;
	for(int v : g[u]) {
		if(v != pre) {
			child++;
			dfs(v, u);
		}
	}
	if(child == 0) {
		is_leaf[u] = 1;
	}
}

void path(int u) {
	vector<int> A;
	while(true) {
		A.push_back(u);
		if(u == par[u]) {
			break;
		}
		u = par[u];
	}
	reverse(A.begin(), A.end());
	for(int x : A) {
		cout << x << ' ';
	}
	cout << '\n';
}

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		g[i].clear();
	}
	memset(is_leaf, false, sizeof(is_leaf));
	for(int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	for(int i = 1; i <= n; i++) {
		if(is_leaf[i]) {
			path(i);
		}
	}
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
