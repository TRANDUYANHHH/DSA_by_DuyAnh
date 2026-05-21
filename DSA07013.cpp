// @author: tranDuyAnh

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 10
#endif

int cal(int a, int b, char c) {
	if(c == '+') {
		return a + b;
	} else
	if(c == '*') {
		return a * b;
	} else
	if(c == '/') {
		return a / b;
	} else {
		return a - b;
	}
}

void solve() {
	string s;
	cin >> s;
	stack<int> st;
	for(char c : s) {
		if(c >= '0' && c <= '9') {
			st.push(c - '0');
		} else {
			int a = st.top(); st.pop();
			int b = st.top(); st.pop();
			int ans = cal(b, a, c);
			st.push(ans);
		}
	}
	cout << st.top();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) {
		solve();
		cout << '\n';
	}
  return 0;  
}
