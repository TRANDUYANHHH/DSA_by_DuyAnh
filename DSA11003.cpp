/**
 *  author: @tranDuyAnh
 **/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
const int maxn = 1e4 + 5, mod = 1e9 + 7;

vector<int> node[maxn];

void solve(){
	for(int i = 0; i < maxn; i++){
		node[i].clear();
	};
	int n;
	cin >> n;
	vector<int> is_par(maxn);
	vector<int> is_child(maxn);
	for(int i = 0; i < n; i++){
		int u, v;
		char c;
		cin >> u >> v >> c;
		is_par[u] = true;
		is_child[v] = true;
		if(node[u].size() == 0){
			node[u] = vector<int>(2, 0);
		}
		if(c == 'L') node[u][0] = v;
		else node[u][1] = v;
	}
	int root = -1;
	for(int i = 0; i < maxn; i++){
		if(is_par[i] and not is_child[i]){
			root = i;
			break;
		}
	}
	vector<pair<int,int>> a;
	queue<pair<int,int>> q;
	q.emplace(root, 0);
	int mx = 0;
	while(q.size()){
		pair<int,int> t = q.front();
		q.pop();
		a.push_back(t);
		mx = max(mx, t.second);
		for(auto v : node[t.first]){
			if(v) q.emplace(v, t.second + 1);
		}	
	}
	vector<vector<int>> lev(mx + 1);
	for(auto [x, y] : a){
		lev[y].push_back(x);
	}
	for(auto arr : lev){
		for(auto x : arr){
			cout << x << ' ';
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

