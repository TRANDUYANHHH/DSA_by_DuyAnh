/**
 *  author: @tranDuyAnh
 **/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
const int maxn = 3e5 + 5, mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int,int>> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(all(a));
		int l = 0;
		int mx = -1;
		int min_idx = n + 1;
		for(int i = 0; i < n; i++){
			while(a[l].first < a[i].first){
				min_idx = min(min_idx, a[l].second);
				l++;
			}
			mx = max(mx, a[i].second - min_idx);
		}
		cout << mx << endl;
	}
	return 0;
}
