// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

void max_self(int &x, int y) {
	x = max(x, y);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		vector<vector<int>> dp(n, vector<int>(k));
		for(int i = 0; i < n; i++) {
			dp[i][a[i] % k] = 1;
			for(int j = 0; j < i; j++) {
				for(int x = 0; x < k; x++) {
					if(dp[j][x]) {
						max_self(dp[i][(a[i] + x) % k], dp[j][x] + 1);
					}
				}
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			max_self(ans, dp[i][0]);
		}
		cout << ans << '\n';
	}
  return 0;  
}
