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
		int n, m;
		cin >> n >> m;
		vector<vector<int64_t>> dp(n + 1, vector<int64_t>(m + 1));
		dp[0][0] = 1;
		int dx[] = {-1, 0};
		int dy[] = {0, -1};
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= m; j++) {
				for(int k : {0, 1}) {
					int ni = i + dx[k];
					int nj = j + dy[k];
					if(ni >= 0 && nj >= 0) {
						dp[i][j] += dp[ni][nj];
					}
				}
			}
		}
		cout << dp[n][m] << '\n';
	}
  return 0;  
}
