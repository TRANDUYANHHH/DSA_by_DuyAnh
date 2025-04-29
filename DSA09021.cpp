/**
 *    author: tranDuyAnh
 *    created: 30.04.2025 00:59:57
**/
#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> adj[n + 1];
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int x;
			cin >> x;
			if(x){
				adj[i].push_back(j);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(auto x : adj[i]){
			cout << x << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	// cin >> t;
	while(t--){
		solve();
		cout << '\n';
	}
	return 0;
}
