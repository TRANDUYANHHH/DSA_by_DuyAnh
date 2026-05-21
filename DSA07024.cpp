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
		vector<int> a(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
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
			if(pre[i] + suf[i] - 1 >= a[i]) {
				ans = max(ans, a[i]);
			}
		}
		cout << ans << '\n';
	}
  return 0;  
}
