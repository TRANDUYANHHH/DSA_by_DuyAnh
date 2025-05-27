/**
 *  author: @tranDuyAnh
 **/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
const int maxn = 1e3 + 5, mod = 1e9 + 7;
int n, m;
vector<int> G[maxn];
vector<pair<int,int>> E;
bool vis[maxn];
void DFS(int u, pair<int, int> edge){
	vis[u] = true;
	for(int x : G[u]){
		pair<int,int> t = {min(u, x), max(u, x)};
		if(t != edge && !vis[x]){
			DFS(x, edge);
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) G[i].clear();
	E.clear();
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
		E.emplace_back(min(x, y), max(x, y));
	}
	sort(all(E));
	for(pair<int,int> x : E){
		memset(vis, false, sizeof(vis));
		DFS(1, x);
		for(int i = 1; i <= n; i++) {
			if(!vis[i]){
				cout << x.first << ' ' << x.second << ' ';
				break;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		solve();
		cout << '\n';
	}
	return 0;
}

