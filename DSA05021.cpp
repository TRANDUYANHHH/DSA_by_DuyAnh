// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i].second >> a[i].first;
		}
		sort(a.begin(), a.end());
		int ans = 1;
		int cur = a[0].first;
		for(int i = 1; i < n; i++) {
			if(a[i].second > cur) {
				ans++;
				cur = a[i].first;
			}
		}
		cout << ans << '\n';
	}
  return 0;  
}
