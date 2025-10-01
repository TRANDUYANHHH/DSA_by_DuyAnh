// @author : tranDuyAnh

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
const int maxN = 1005;
int C[maxN];
vector<int> G[maxN];
bool vis[maxN];
void dfs(int u, int num){
    vis[u] = true;
    C[u] = num;
    for(int x : G[u]){
        if(!vis[x]){
            dfs(x, num);
        }
    }
}
void solve(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        G[i].clear();
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            dfs(i, cnt);
            cnt++;
        }
    }
    int q;
    cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        --u, --v;
        cout << (C[u] == C[v] ? "YES" : "NO") << '\n';
    }
}

int main() {
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
