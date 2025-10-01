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
void bfs(int u){
    queue<int> q;
    q.push(u);
    P[u] = -1;
    vis[u] = true;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(int x : G[f]){
            if(!vis[x]){
                P[x] = f;
                vis[x] = true;
                q.push(x);
            }
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
    bfs(S);
    if(!vis[T]){
        cout << -1;
        return;
    }
    vector<int> R;
    int cur = T;
    while(cur != -1){
        R.push_back(cur);
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
