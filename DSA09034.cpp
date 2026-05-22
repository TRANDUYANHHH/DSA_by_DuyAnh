// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;
vector<string> A;

void dfs(int i, int j) {
	A[i][j] = '.';
	for(int k = 0; k < 8; k++) {
		int ni = i + dx[k];
		int nj = j + dy[k];
		if(ni >= 0 && nj >= 0 && ni < n && nj < m && A[ni][nj] == 'W') {
			dfs(ni, nj);
		}
	}
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		A.push_back(s);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(A[i][j] == 'W') {
				ans++;
				dfs(i, j);
			}
		}
	}
	cout << ans;
  return 0;  
}
