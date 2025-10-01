// @author : tranDuyAnh

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
const int maxN = 1005;
int N, M, S, T;
int P[maxN];
vector<int> G[maxN];
bool vis[maxN];
void dfs(int u){
    vis[u] = true;
    for(int x : G[u]){
        if(!vis[x]){
            P[x] = u;
            dfs(x);
        }
    }
}
void solve(){
    cin >> N >> M >> S >> T;
    --S, --T;
    for(int i = 0; i < N; i++){
        G[i].clear();
    }
    memset(vis, false, sizeof(vis));
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
    }
    for(int i = 0; i < N; i++) sort(all(G[i]));
    dfs(S);
    if(!vis[T]){
        cout << -1;
        return;
    }
    vector<int> R;
    int cur = T;
    while(true){
        R.push_back(cur);
        if(cur == S){
            break;
        }
        cur = P[cur];
    }
    reverse(all(R));
    for(int x : R){
        cout << x + 1 << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
        cout << '\n';
    }
    return 0;
}
