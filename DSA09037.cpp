// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

int k, n, m;
const int maxN = 1005;
vector<int> g[maxN];
int vis[maxN];
vector<int> V;

void dfs(int u, int pre) {
	vis[u] = true;
	if(u != pre) {
		V.push_back(u);
	}
	for(int v : g[u]) {
		if(!vis[v]) {
			dfs(v, u);
		}
	}
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> k >> n >> m;
  vector<int> A(k);
  for(int i = 0; i < k; i++) {
  	cin >> A[i];
  }
  for(int i = 0; i < m; i++) {
  	int u, v;
  	cin >> u >> v;
  	g[u].push_back(v);
  }
  int ans = 0;
	for(int i = 1; i <= n; i++) {
		V = {i};
		memset(vis, 0, sizeof(vis));
		dfs(i, i);
		bool ok = true;
		for(int x : A) {
			if(count(V.begin(), V.end(), x) == 0) {
				ok = false;
				break;
			}
		}
		if(ok) {
			ans++;
		}
	}
	cout << ans;
  return 0;  
}   
