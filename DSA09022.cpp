/**
 *    author: tranDuyAnh
 *    created: 30.04.2025 01:30:01
**/
#include <bits/stdc++.h>

using namespace std;

bool vis[1001];
vector<int> adj[1001];

void dfs(int u){
	cout << u << ' ';
	vis[u] = true;
	for(auto x : adj[u]){
		if(!vis[x]) {
			dfs(x);
		}
	}
}
void solve(){
	int n, m, u;
	cin >> n >> m >> u;
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++){
		adj[i].clear();
	}
	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}
	dfs(u);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
	#endif
	int t;
	cin >> t;
	while(t--){
		solve();
		cout << '\n';
	}
	return 0;
}
