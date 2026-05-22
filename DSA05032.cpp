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
		string s;
		cin >> s;
		int n = (int) s.size();
		vector<vector<int>> dp(n, vector<int>(n));
		for(int i = 0; i < n - 1; i++) {
			if(s[i] != s[i + 1]) {
				dp[i][i + 1] = 1;
			}
		}
		for(int l = 3; l <= n; l++) {
			for(int i = 0; i + l - 1 < n; i++) {
				int r = i + l - 1;
				dp[i][r] = min(dp[i + 1][r], dp[i][r - 1]) + 1;
				if(s[i] == s[r]) {
					dp[i][r] = min(dp[i][r], dp[i + 1][r - 1]);
				}
			}
		}
		cout << dp[0][n - 1] << '\n';
	}
  return 0;  
}	
