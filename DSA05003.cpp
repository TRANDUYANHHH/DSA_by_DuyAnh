// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

int Max(vector<int> a) {
	return *max_element(a.begin(), a.end());
}	

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1)));
		string a, b, c;
		cin >> a >> b >> c;
		a = '_' + a;
		b = '_' + b;
		c = '_' + c;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) for(int u = 1; u <= k; u++) {
			if(a[i] == b[j] && b[j] == c[u]) {
				dp[i][j][u] = dp[i - 1][j - 1][u - 1] + 1;
			} else {
				dp[i][j][u] = Max({dp[i - 1][j][u], dp[i][j - 1][u], dp[i][j][u - 1],
													 dp[i - 1][j - 1][u], dp[i - 1][j][u - 1], dp[i][j - 1][u - 1]
				});
			}
		}
		cout << dp[n][m][k] << '\n';
	}
  return 0;  
}
