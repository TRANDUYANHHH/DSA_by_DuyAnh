// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

struct p {
	int val, aa, bb;
	string ss;
	p(int x, int y, int z, string s): val(x), aa(y), bb(z), ss(s) {};
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int A, B;
		cin >> A >> B;
		vector<vector<vector<bool>>> dp(A + 1, vector<vector<bool>>(B + 1, vector<bool>(10, -1)));
		for(int x = 1; x <= 9; x++) {
			if(x <= A && x * x <= B) {
				dp[x][x * x][x] = true;
			}
		}
		for(int i = 1; i <= A; i++) {
			for(int j = 1; j <= B; j++) {
				for(int x = 1; x < 10; x++) {
					if(i - x >= 0 && j - x * x >= 0) {
						for(int y = 9; y >= 1; y--) {
							if(dp[i - x][j - x * x][y]) {
								dp[i][j][x] = true;
								break;
							}
						}
					}
				}
			}
		}
		vector<vector<vector<int>>> vis(A + 1, vector<vector<int>>(B + 1, vector<int>(10, false)));
		// bfs ?
		queue<p> q;
		for(int i = 1; i <= 9; i++) {
			if(dp[A][B][i]) {
				q.push(p(i, A, B, to_string(i)));
				vis[A][B][i] = true;
			}
		}
		vector<string> se;
		while(!q.empty()) {
			auto ff = q.front();
			int nA = ff.aa - ff.val;
			int nB = ff.bb - ff.val * ff.val;
			if(nA == 0 && nB == 0) {
				se.push_back(ff.ss);
			}
			q.pop();
			int ii = ff.val;
			for(int i = 1; i <= 9; i++) {
				if(nA >= 0 && nB >= 0 && !vis[nA][nB][i] && dp[nA][nB][i]) {
					vis[nA][nB][i] = true;
					string t = ff.ss + to_string(i);
					q.push(p(i, nA, nB, t));
				}
			}
		}
		auto cmp = [](string x, string y) {
			if(x.size() == y.size()) {
				return x < y;
			} 
			return x.size() < y.size();
		};
		sort(se.begin(), se.end(), cmp);
		if(se.size() == 0) {
			cout << -1;
		} else {
			cout << *se.begin();
		}
		cout << '\n';
	}
  return 0;  
}
