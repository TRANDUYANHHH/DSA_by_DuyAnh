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
		int n, k;
		cin >> n >> k;
		vector<vector<int>> dp(n, vector<int>(k + 1));
		for(int i = 1; i <= min(9, k); i++) {
			dp[0][i] = 1;
		}
		const int mod = 1e9 + 7;
		for(int i = 1; i < n; i++) {
			for(int j = 1; j <= k; j++) {
				for(int x = 0; x < 10; x++) {
					if(j - x >= 0) {
						dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % mod;
					}
				}
			}
		}
		cout << dp[n - 1][k] << '\n';
	}
  return 0;  
}
