// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

int calc(vector<int> a) {
	int n = (int) a.size();
	vector<int> pre(n), suf(n);
	stack<int> st;
	for(int i = 0; i < n; i++) {
		while(!st.empty() && a[st.top()] >= a[i]) {
			st.pop();
		}
		if(st.empty()) {
			pre[i] = i + 1;
		} else {
			pre[i] = i - st.top();
		}
		st.push(i);
	}
	while(!st.empty()) st.pop();
	for(int i = n - 1; i >= 0; i--) {
		while(!st.empty() && a[st.top()] >= a[i]) {
			st.pop();
		}
		if(st.empty()) {
			suf[i] = n - i;
		} else {
			suf[i] = st.top() - i;
		}
		st.push(i);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, (pre[i] + suf[i] - 1) * a[i]);
	}
	return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> M(n, vector<int>(m));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> M[i][j];
			}
		}
		int ans = 0;
		for(int r = 0; r < n; r++) {
			vector<int> A(m);
			for(int j = 0; j < m; j++) {
				int i = r;
				while(i >= 0 && M[i][j] == 1) {
					A[j]++;
					i--;
				}
			}
			ans = max(ans, calc(A));
		}
		for(int c = 0; c < m; c++) {
			vector<int> A(n);
			for(int i = 0; i < n; i++) {
				int j = c;
				while(j >= 0 && M[i][j] == 1) {
					j--;
					A[i]++;
				}
			}
			ans = max(ans, calc(A));
		}
		cout << ans << '\n';
	}
  return 0;  
}
