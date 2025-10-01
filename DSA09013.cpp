// @author : tranDuyAnh

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
int M[1001][1001];
vector<int> G[1001];
bool vis[1001];
void dfs(int u){
    vis[u] = true;
    for(int x : G[u]){
        if(!vis[x] && M[u][x]){
            dfs(x);
        }
    }
}
void solve(){
    memset(M, 0, sizeof(M));
    memset(vis, 0, sizeof(vis));
    int N, m;
    cin >> N >> m;
    for(int i = 0; i < N; i++) G[i].clear();
    vector<pair<int,int>> E;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(u > v) swap(u, v);
        E.emplace_back(u, v);
        M[u][v] = 1;
        M[v][u] = 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int C = 0;
    for(int i = 0; i < N; i++){
        if(!vis[i]){
            C++;
            dfs(i);
        }
    }
    sort(all(E));
    for(auto p : E){
        M[p.first][p.second] = 0;
        M[p.second][p.first] = 0;
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        for(int i = 0; i < N; i++){
            if(!vis[i]){
                cnt++;
                dfs(i);
            }
        }
        if(cnt > C){
            cout << p.first + 1 << ' ' << p.second + 1 << ' ';
        }
        M[p.first][p.second] = 1;
        M[p.second][p.first] = 1;
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
